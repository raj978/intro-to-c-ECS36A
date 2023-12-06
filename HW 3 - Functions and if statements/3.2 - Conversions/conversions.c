#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * @param input is used to store the input that is fed into the function from the user input.
 * @param type is used by the isValidFormat function to determine the type of format to check for.
 * the text alpha-dt is used to check for Distance or Temperature input.
 * the text alpha-t-fck is used to check for the units for the temperature units from user input.
 * the text alpha-d-ifym is used to check for the units for the distance units for the user input.
 *
 */

bool isValidConversion(char input, char type[10])
{
    if (strcmp(type, "alpha-dt") == 0)
    {
        if (input == 'd' || input == 'D')
        {
            return true;
        }
        else if (input == 't' || input == 'T')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (strcmp(type, "alpha-t-fck") == 0)
    {
        if (input == 'f' || input == 'F')
        {
            return true;
        }
        else if (input == 'c' || input == 'C')
        {
            return true;
        }
        else if (input == 'k' || input == 'K')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (strcmp(type, "alpha-d-ifym") == 0)
    {
        if (input == 'i' || input == 'I')
        {
            return true;
        }
        else if (input == 'f' || input == 'F')
        {
            return true;
        }
        else if (input == 'y' || input == 'Y')
        {
            return true;
        }
        else if (input == 'm' || input == 'M')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * This function is used to convert the values of any Distance to Inches
 * @param initialNum is used to store the value of the initial value input by the user.
 * @param initialUnit is used to store the units corresponding to initialNum.
 * @param finalNum is used to store the changed value of initialNum converted to Inches.
 */

double ConvertToInches(double initialNum, char initialUnit)
{
    switch (toupper(initialUnit))
    {
    case 'I':
        break;

    case 'F':
        initialNum = initialNum * 12;
        break;

    case 'Y':
        initialNum = initialNum * 36;
        break;

    case 'M':
        initialNum = initialNum * 63360;
        break;
    }
    return initialNum;
}

/**
 * This function is used to convert the values of any Temperature to Celsius.
 * @param initialNum is used to store the value of the initial value input by the user.
 * @param initialUnit is used to store the units corresponding to initialNum.
 * @param finalNum is used to store the changed value of initialNum converted to Inches.
 */

double ConvertToCelsius(double initialNum, char initialUnit)
{
    switch (toupper(initialUnit))
    {
    case 'F':
        initialNum = (initialNum - 32) * 5 / 9;
        break;

    case 'C':
        break;

    case 'K':
        initialNum = initialNum - 273.15;
        break;
    }
    return initialNum;
}

double IdentifyDConversion(double initialVal, char initialUnit, double finalVal, char finalUnit)
{

    initialVal = ConvertToInches(initialVal, initialUnit);
    // To convert the initialUnit to Inches
    switch (toupper(finalUnit))
    {
    case 'I':
        finalVal = initialVal;
            break;

    case 'F':
        finalVal = initialVal / 12.0;
            // To convert the initialUnit to Fet
        break;

    case 'Y':
        finalVal = initialVal / 36.0;
            break;

    case 'M':
        finalVal = initialVal / 63360.0;
            break;
    }
    return finalVal;
}

double IdentifyTConversion(double initialVal, char initialUnit, double finalVal, char finalUnit)
{
    initialVal = ConvertToCelsius(initialVal, initialUnit);
    switch (toupper(finalUnit))
    {

    case 'F':
        finalVal = (initialVal * 9.0 / 5.0) + 32.0;
            break;

    case 'C':
        finalVal = initialVal;
            break;

    case 'K':
        finalVal = (initialVal + 273.15);
            break;
    }
    return finalVal;
}

/**
 * Main function is used to get the main input and give outputs
 * Used to call the Input Validation and Conversion functions
 */
int main(void)
{
    char conversionType[20];
    char initialUnit[20];
    char finalUnit[20];
    char alphaType[20];

    double initialVal = 0;
    double finalVal = 0;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");

    /**
     * @char: conversionType is used to store the value to the first user input.
     * @char: initialUnit is used to store the Unit that the user is trying to convert from
     * @char: finalUnit is the Unit that the user is trying to convert to.
     * @char: alphaType is used to assign the right value to the isValidConversion method call.
     * @double: initialVal is used to store the numerical value which is converted to another value.
     * @double: finalVal is the final value that the initialVal is converted to.
     */

    /**
     * The first input for the conversion type has 2 Input validations
     * The first one is to check for a Valid Format to ensure a character is input
     * The second is to check for a Valid conversion that is the right character among the 4 choices available.
     */

    printf("Enter your choice: ");
    scanf(" %s", conversionType);

    if ((isalpha(conversionType[0]) || ispunct(conversionType[0])) && strlen(conversionType) == 1)
    {
        strcpy(alphaType, "alpha-dt");
        if (isValidConversion(conversionType[0], alphaType))
        {
            // Nothing in the nested-if since if the program continues that there are no errors.
        }
        else
        {
            printf("Unknown conversion type %c chosen. Ending program.\n", toupper(conversionType[0]));
            exit(0);
        }
    }
    else
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    /**
     * The if statement is used to print the right statement depending on the user selected category.
     */

    if (conversionType[0] == 'T' || conversionType[0] == 't')
    {
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        strcpy(alphaType, "alpha-t-fck");
    }
    else
    {
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        strcpy(alphaType, "alpha-d-ifym");
    }

    /**
     * The second input for the conversion type has 2 Input validations
     * The first one is to check for a Valid Format to ensure a character is input
     * The second is to check for a Valid conversion that is the right character among the 4 choices available.
     * This field takes in 2 inputs. The value which is to be converted as well as the units.
     * @param initialVal is the value which is to be converted
     * @param initialUnit is the unit which is to be converted.
     */

    scanf("%lf %s", &initialVal, initialUnit);

    if ((initialVal >= 0 || initialVal <= 0) && (isalpha(initialUnit[0]) || ispunct(initialUnit[0]) || (int)(initialUnit[0]) >= 0 || (int)(initialUnit[0]) <= 0 ) && strlen(initialUnit) == 1)
    {
        if (isValidConversion(initialUnit[0], alphaType))
        {
            // Nothing in the nested-if since if the program continues that there are no errors.
        }
        else
        {
            if (conversionType[0] == 'T' || conversionType[0] == 't')
            {
                printf("%c is not a valid temperature type. Ending program.\n", toupper(initialUnit[0]));
                exit(0);
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.\n", toupper(initialUnit[0]));
                exit(0);
            }
        }
    }
    else
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    /**
     * The if statement is used to print the right statement depending on the user selected category.
     */

    if (conversionType[0] == 'T' || conversionType[0] == 't')
    {
        printf("Enter the new unit type (F, C, or K): ");
    }
    else
    {
        printf("Enter the new unit type (I,F,Y,M): ");
    }

    /**
     * The third input for the conversion type has 2 Input validations
     * The first one is to check for a Valid Format to ensure a character is input
     * The second is to check for a Valid conversion that is the right character among the 4 choices available.
     * @param finalUnit is the unit which the program converts their unit to.
     */

    scanf(" %s", finalUnit);

    if ((isalpha(finalUnit[0]) || ispunct(finalUnit[0]) || (int)(finalUnit[0]) >= 0 || (int)(finalUnit[0]) <= 0) && strlen(finalUnit) == 1)
    {
        if (isValidConversion(finalUnit[0], alphaType))
        {
            // Nothing in the nested-if since if the program continues that there are no errors.
        }
        else
        {
            if (conversionType[0] == 'T' || conversionType[0] == 't')
            {
                printf("%c is not a valid temperature type. Ending program.\n", toupper(finalUnit[0]));
                exit(0);
            }
            else
            {
                printf("%c is not a valid distance type. Ending program.\n", toupper(finalUnit[0]));
                exit(0);
            }
        }
    }
    else
    {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }

    if (strcmp(alphaType, "alpha-t-fck") == 0)
    {
        finalVal = IdentifyTConversion(initialVal, initialUnit[0], finalVal, finalUnit[0]);
    }
    else if (strcmp(alphaType, "alpha-d-ifym") == 0)
    {
        finalVal = IdentifyDConversion(initialVal, initialUnit[0], finalVal, finalUnit[0]);
    }
    printf("%.2lf%c is %.2lf%c\n", initialVal, toupper(initialUnit[0]), finalVal, toupper(finalUnit[0]));
}