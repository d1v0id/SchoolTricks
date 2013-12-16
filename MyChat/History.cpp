#include "History.h"

        History::History(){
          Beg = NULL;
          NowBeg = NULL;
        }

        History::~History(){  // ������� ������(�������� ������ �������)
          RecordHist *F;
          F = Beg;
          while(F!=NULL) // ���� �� ��������� ������� �������
          {
            Beg = F->Next;
            delete F;
            F = Beg;
          }
        }

        bool History::Add(AnsiString value){ // �-��� ���������� ����� � �������
          if(!FindSameHOST(value)) // ���� ���� �� ����������� � �������
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

        void History::SaveHist(char *FileName){ // �-��� ���������� ������ ������� �� ������ � ����
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

        void History::LoadHist(char *FileName){ // �-��� �������� ������ ������� �� �����
          ifstream in(FileName);

          char HOST[256];
          while(!in.eof()) // ���� �� ��������� ����� �����
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
          if(NowBeg == NULL) return 1; // ���������� TRUE
          else return 0; // ���������� FALSE
        }

        bool History::FindSameHOST(AnsiString FindHost){ // ����� ���������� ������
          RecordHist *F;
          F = Beg;
          while(F!=NULL)
          {
            if(F->HOST == FindHost) return 1;
            F = F->Next;
          }
          return 0;
        }
