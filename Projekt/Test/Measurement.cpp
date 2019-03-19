#include "Measurement.h"

Measurement::Measurement()
{
    duration = 0;
}

void Measurement::startTimer()
{
	//Ustawiamy pocz�tkowy czas wykonywania.
    startTime = std::chrono::high_resolution_clock::now();
}

void Measurement::stopTimer()
{
	//Ustawiamy ko�cowy czas wykonywania i zapisujemy r�nic� do 'duration'.
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> time = endTime - startTime;
    duration = time.count();
}

double Measurement::getDuration()
{
    return duration;
}