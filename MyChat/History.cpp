#include "History.h"

        History::History(){
          Beg = NULL;
          NowBeg = NULL;
        }

        History::~History(){  // Очистка памяти(удаление списка истории)
          RecordHist *F;
          F = Beg;
          while(F!=NULL) // Пока не закончена цепочка Хистори
          {
            Beg = F->Next;
            delete F;
            F = Beg;
          }
        }

        bool History::Add(AnsiString value){ // Ф-ция добавления хоста в историю
          if(!FindSameHOST(value)) // Если хост не повторяется в истории
          {
           RecordHist *F;
           F = new RecordHist;
           F->HOST = value;
           F->Next = Beg;
           Beg = F;
           return 1;
          }
          return 0;
        }

        void History::SaveHist(char *FileName){ // Ф-ция сохранения списка истории из памяти в файл
          ofstream out(FileName);

          RecordHist *F;
          F = Beg;
          while(F!=NULL)
          {
            Beg = F->Next;
            AnsiString str(F->HOST);
            out<<F->HOST.c_str()<<'\n';
            F = Beg;
          }
        }

        void History::LoadHist(char *FileName){ // Ф-ция загрузки списка истории из файла
          ifstream in(FileName);

          char HOST[256];
          while(!in.eof()) // Пока не достигнут конец файла
          {
            in>>HOST;
            Add(HOST);
          }
        }

        AnsiString History::Next()
        {
          RecordHist *F;
          F = NowBeg;
          NowBeg = NowBeg->Next;
          return F->HOST;
        }

        void History::GoToBeg()
        {
          NowBeg = Beg;
        }

        bool History::EndOfList()
        {
          if(NowBeg == NULL) return 1; // возвратить TRUE
          else return 0; // возвратить FALSE
        }

        bool History::FindSameHOST(AnsiString FindHost){ // Поиск одинаковых хостов
          RecordHist *F;
          F = Beg;
          while(F!=NULL)
          {
            if(F->HOST == FindHost) return 1;
            F = F->Next;
          }
          return 0;
        }
