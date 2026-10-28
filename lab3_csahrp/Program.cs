using System.Runtime.CompilerServices;
using lab3_csahrp;
Film film = new Film("Смешарики", 37, 12);
film.PrintInfo();
film.CheckAge(7);
film.ChangeName("Лунтик");
Console.WriteLine(film);
Console.WriteLine("=== Демонстрация class ===");
Film film1 = new Film("Смешарики", 37, 0);
Film film2 = film1;
film2.ChangeName("Лунтик");
Console.WriteLine($"film1: {film1.Name}");
Console.WriteLine($"film2: {film2.Name}");
Console.WriteLine("\n=== Демонстрация struct ===");
FilmStruct struct1 = new FilmStruct("Смешарики");
FilmStruct struct2 = struct1;
struct2.name = "Лунтик";
Console.WriteLine($"struct1: {struct1.name}");
Console.WriteLine($"struct2: {struct2.name}");
Console.WriteLine("=== Проверка IDisposable ===");
using (CinemaLog log = new CinemaLog("Кинотеатр Мир"))
{
    log.Write("Начался показ фильма Смешарики");
}
Console.WriteLine("=== Проверка сборщика мусора ===");
WeakReference<Film> watcher = CreateTemporary();
GC.Collect();
GC.WaitForPendingFinalizers();
Console.WriteLine(watcher.TryGetTarget(out _));
[MethodImpl(MethodImplOptions.NoInlining)]
static WeakReference<Film> CreateTemporary()
{
    Film temp = new Film("Смешарики", 90, 0);
    return new WeakReference<Film>(temp);
}
Console.WriteLine("Программа завершена!");