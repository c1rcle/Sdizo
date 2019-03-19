#include <chrono>

/// Klasa s�u��ca do mierzenia czasu wykonywania algorytm�w.
class Measurement
{
private:
	/// Zmienna przechowuj�ca informacj� o d�ugo�ci wykonywania pewnego segmentu (mikrosekundy).
    double duration;
	/// Zmienna przechowuj�ca czas startu pomiaru.
    std::chrono::high_resolution_clock::time_point startTime;
	/// Zmienna przechowuj�ca czas ko�ca pomiaru.
    std::chrono::high_resolution_clock::time_point endTime;
public:
	/// Konstruktor klasy Measurement.
    Measurement();
	/// Rozpoczyna odmierzanie czasu.
    void startTimer();
	/// Ko�czy odmierzanie czasu.
    void stopTimer();
	/// Zwraca czas w mikrosekundach, kt�ry up�yn�� dla ostatniego pomiaru.
    double getDuration();
};