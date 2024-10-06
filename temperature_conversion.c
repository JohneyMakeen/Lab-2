#include <stdio.h>

// Function prototypes (declarations)
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

// Main function
int main() {
    float temperature;
    int user_input_scale, user_target_scale;    

    // Input temperature
    printf("Enter the Temperature: ");
    scanf("%f", &temperature);

    // Input current scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &user_input_scale);

    // Validate negative Kelvin temperature
    if (user_input_scale == 3 && temperature < 0) {
        printf("Invalid Temperature Value: Kelvin temperature cannot be negative.\n");
        return 1;  
    }

    // Input target scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &user_target_scale);

    // Check if input and target scales are the same
    if (user_input_scale == user_target_scale) {
        printf("Invalid conversion choices: Input and target scale are the same.\n");
        return 1; 
    }

    // Validate the scale choices
    if (user_input_scale < 1 || user_input_scale > 3 || user_target_scale < 1 || user_target_scale > 3) {
        printf("Invalid scale choice. Please select (1) for Celsius, (2) for Fahrenheit, or (3) for Kelvin.\n");
        return 1; 
    }

    // Conversion logic
    float converted_temperature = 0.0;
    float original_celsius = temperature; // Store original Celsius value

    // Perform conversion based on user input and update original_celsius if necessary
    if (user_input_scale == 1 && user_target_scale == 2) {
        converted_temperature = celsius_to_fahrenheit(temperature);
    } else if (user_input_scale == 1 && user_target_scale == 3) {
        converted_temperature = celsius_to_kelvin(temperature);
    } else if (user_input_scale == 2 && user_target_scale == 1) {
        converted_temperature = fahrenheit_to_celsius(temperature);
        original_celsius = converted_temperature;  // Update original Celsius value after conversion
    } else if (user_input_scale == 2 && user_target_scale == 3) {
        converted_temperature = fahrenheit_to_kelvin(temperature);
        original_celsius = fahrenheit_to_celsius(temperature);  // Update original Celsius value
    } else if (user_input_scale == 3 && user_target_scale == 1) {
        converted_temperature = kelvin_to_celsius(temperature);
        original_celsius = converted_temperature;  // Update original Celsius value
    } else if (user_input_scale == 3 && user_target_scale == 2) {
        converted_temperature = kelvin_to_fahrenheit(temperature);
        original_celsius = kelvin_to_celsius(temperature);  // Update original Celsius value
    } else {
        printf("Invalid Conversion\n");
        return 1;  
    }

    // Output the converted temperature
    printf("Converted Temperature: %.2f\n", converted_temperature);

    // Categorize and provide advisory based on original Celsius value
    categorize_temperature(original_celsius);

    return 0;
}

// Function definitions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit_to_celsius(fahrenheit)) + 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature Category: Freezing\n");
        printf("Weather Advisory: Wear a heavy jacket.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius <= 25) {  // Include up to and including 25°C as Comfortable
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) {  // Hot starts strictly above 25°C
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Wear light clothing.\n");
    } else {
        printf("Temperature Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors and stay hydrated.\n");
    }
}
