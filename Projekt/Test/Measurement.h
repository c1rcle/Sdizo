#include <chrono>

/// Klasa s³u¿¹ca do mierzenia czasu wykonywania algorytmów.
class Measurement
{
private:
	/// Zmienna przechowuj¹ca informacjê o d³ugoœci wykonywania pewnego segmentu (mikrosekundy).
    double duration;
	/// Zmienna przechowuj¹ca czas startu pomiaru.
    std::chrono::high_resolution_clock::time_point startTime;
	/// Zmienna przechowuj¹ca czas koñca pomiaru.
    std::chrono::high_resolution_clock::time_point endTime;
public:
	/// Konstruktor klasy Measurement.
    Measurement();
	/// Rozpoczyna odmierzanie czasu.
    void startTimer();
	/// Koñczy odmierzanie czasu.
    void stopTimer();
	/// Zwraca czas w mikrosekundach, który up³yn¹³ dla ostatniego pomiaru.
    double getDuration();
};