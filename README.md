# C Programming Project 1

## Files

- `water_quality.c`: Q1, water-quality monitor
- `transactions.c`: Q2, mobile-money transaction system
- `deliveries.c`: Q3, delivery distance analysis
- `parking.ino`: Q4, Arduino smart parking system (Tinkercad)
- `.pdf`: report with explanations, screenshots and block diagram

## Compile and run

Q1 to Q3 were written in C and compiled with GCC:

```
gcc water_quality.c -o water_quality -lm
gcc transactions.c -o transactions
gcc deliveries.c -o deliveries
```

Run each one with `./water_quality`, `./transactions` or `./deliveries`. The `-lm` flag links the math library, which Q1 needs for `fabs`.

## Programs

**Q1: Water Quality.** Reads temperature and turbidity, calculates the water-quality index, and prints a report with the status (Good, Warning or Critical).

**Q2: Transactions.** Menu-driven program with deposit, withdrawal, balance inquiry, transaction summary and exit. It rejects invalid and negative amounts and withdrawals above the balance.

**Q3: Deliveries.** Reads the distances of N routes into an integer array, then calculates the total, average, longest route and the number of routes above a limit. It also calculates the total with a recursive function.

**Q4: Smart Parking.** An HC-SR04 sensor measures distance. If a vehicle is closer than 100 cm, the red LED and buzzer turn on. Otherwise the green LED is on. Pins: Trig 9, Echo 10, green LED 4, red LED 5, buzzer 6.

To run Q4, open the circuit in Tinkercad Circuits, paste in `parking.ino`, start the simulation and open the Serial Monitor. Change the sensor distance to test.
