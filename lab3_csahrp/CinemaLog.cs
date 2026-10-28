using System;
namespace lab3_csahrp
{
    class CinemaLog : IDisposable
    {
        private string title;
        public CinemaLog(string newTitle)
        {
            title = newTitle;
            Console.WriteLine("Журнал открыт: " + title);
        }
        public void Write(string text)
        {
            Console.WriteLine(text);
        }
        public void Dispose()
        {
            Console.WriteLine("Журнал закрыт: " + title);
        }
    }
}