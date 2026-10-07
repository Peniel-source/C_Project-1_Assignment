#include <stdio.h>
#include <math.h>

/*prototypes */
float calculate_index(float, float);
void print_status(float value);

int main(void)
{
    printf("\n===== WATER QUALITY MONITOR =====\n");

    /*variables */
    float temperature, turbidity, quality_index;

    /*get temperature and turbidity values from user input */
    printf("Enter temperaure: ");
    scanf("%f", &temperature);

    printf("Enter turbidity: ");
    scanf("%f", &turbidity);

    /*pass temperature and turbidity to get index value from calculate_index */
    quality_index = calculate_index(temperature, turbidity);

    /*report */
    printf("\n============== REPORT ==============\n");
    printf("Temperature reads: %.1f°C\n", temperature);
    printf("Turbidity reads: %.1f NTU\n", turbidity);
    printf("------------------------------------\n");
    printf("Water-quality index: %.1f\n", quality_index);
    print_status(quality_index);

    return 0;
}

float calculate_index(float temperature, float turbidity)
{
    /*decalre temp deviation and turbidity penalty */
    float TemperatureDeviation;
    float TurbidityPenalty;

    /*Using fabs here insted of abs because of float values */
    TemperatureDeviation = fabs(temperature - 25.0);

    // set penalty expression with float division
    TurbidityPenalty = turbidity / 2.0;

    /* return the float value as the result of this function */
    return 100 - (TemperatureDeviation + TurbidityPenalty);
}

/*print status will not return anything. print the status directly in main */
void print_status(float value) 
{        
    /*if the quality index is at least 80, it is good */
    if (value >= 80) 
    {
        printf("STATUS: Good\n");
    /*if it's not 80 and above but at least 60, we'll send a warning */   
    } else if (value >= 60) 
    {
        printf("STATUS: Warning\n");
    /* if it falls below 60, the status is criticall */
    } else {
        printf("STATUS: Critical\n");
    }
}
