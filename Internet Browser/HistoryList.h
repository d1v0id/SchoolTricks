/*

 [Name] : ������ ��� ��������� ������� ������
 [Coder] : Konnov Dima aka Divoid

*/

#include <fstream.h> /* ���������� ��� ������ ������ ������ � ���� � ���������� �� �� ���� */

struct RecordHist{   /* �������� ��������� ������� */
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

        ~History(){                    /* ������� ������(�������� ������ �������) */
          RecordHist *F;
          F = Beg;
          while(F!=NULL)               /* ���� �� ��������� ������� ������� � ������ */
          {
            Beg = F->Next;
            delete F;
            F = Beg;
          }
        }

        void Add(AnsiString value){    /* �-��� ���������� ���� � ������� */
          if(!FindSameURL(value))      /* ���� ���� �� ����������� � ������� */
          {
           RecordHist *F;
           F = new RecordHist;
           F->URL = value;
           F->Next = Beg;
           Beg = F;
          }
        }

        void SaveHist(char *FileName){ /* �-��� ���������� ������ ������� �� ������ � ���� */
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

        void LoadHist(char *FileName){ /* �-��� �������� ������ ������� �� ����� */
          ifstream in(FileName);

          char URL[256];
          while(!in.eof())             /* ���� �� ��������� ����� ����� */
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
          if(NowBeg == NULL) return 1; /* ���������� TRUE */
          else return 0;               /* ���������� FALSE */
        }

        bool FindSameURL(AnsiString FindSite){ /* ����� ���������� ������ */
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