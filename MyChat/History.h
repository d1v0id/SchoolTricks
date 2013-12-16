#include <vcl.h>
#include <fstream.h> // Библиотека для записи потока в файл и извлечения из него

struct RecordHist{
 AnsiString HOST;
 RecordHist *Next;
};

class History{
 private:
         RecordHist *Beg, *NowBeg;
 public:
        History();
        ~History();
        bool Add(AnsiString);
        void SaveHist(char *);
        void LoadHist(char *FileName);
        AnsiString Next();
        void GoToBeg();
        bool EndOfList();
        bool FindSameHOST(AnsiString FindHost);
};