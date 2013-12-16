#include <fstream.h> // Библиотека для записи потока в файл и извлечения из него

struct RecordHist{
 AnsiString URL;
 RecordHist *Next;
};

class History{
 private:
         RecordHist *Beg, *NowBeg;

 public:
        History(){
          Beg = NULL;
          NowBeg = NULL; 
        }

        ~History(){  // Очистка памяти(удаление списка истории)
          RecordHist *F;
          F = Beg;
          while(F!=NULL) // Пока не закончена цепочка Хистори
          {
            Beg = F->Next;
            delete F;
            F = Beg;
          }
        }

        void Add(AnsiString value){ // Ф-ция добавления урла в историю
          if(!FindSameURL(value)) // Если сайт не повторяется в истории
          {
           RecordHist *F;
           F = new RecordHist;
           F->URL = value;
           F->Next = Beg;
           Beg = F;
          }
        }

        void SaveHist(char *FileName){ // Ф-ция сохранения списка истории из памяти в файл
          ofstream out(FileName);

          RecordHist *F;
          F = Beg;
          while(F!=NULL)
          {
            Beg = F->Next;
            out<<F->URL.c_str()<<'\n';
            F = Beg;
          }
        }

        void LoadHist(char *FileName){ // Ф-ция загрузки списка истории из файла
          ifstream in(FileName);

          char URL[256];
          while(!in.eof()) // Пока не достигнут конец файла
          {
            in>>URL;
            Add(URL);
          }
        }

        AnsiString Next()
        {
          RecordHist *F;
          F = NowBeg;
          NowBeg = NowBeg->Next;
          return F->URL;
        }

        void GoToBeg()
        {
          NowBeg = Beg;
        }

        bool EndOfList()
        {
          if(NowBeg == NULL) return 1; // возвратить TRUE
          else return 0; // возвратить FALSE
        }

        bool FindSameURL(AnsiString FindSite){ // Поиск одинаковых сайтов
          RecordHist *F;
          F = Beg;
          while(F!=NULL)
          {
            if(F->URL == FindSite) return 1;
            F = F->Next;
          }
          return 0;
        }
};