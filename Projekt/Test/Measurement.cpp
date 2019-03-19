#include "Measurement.h"

Measurement::Measurement()
{
    duration = 0;
}

void Measurement::startTimer()
{
	//Ustawiamy pocz¹tkowy czas wykonywania.
    startTime = std::chrono::high_resolution_clock::now();
}

void Measurement::stopTimer()
{
	//Ustawiamy koñcowy czas wykonywania i zapisujemy ró¿nicê do 'duration'.
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> time = endTime - startTime;
    duration = time.count();
}

double Measurement::getDuration()
{
    return duration;
}