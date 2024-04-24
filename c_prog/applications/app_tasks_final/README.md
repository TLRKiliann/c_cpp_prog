# Financial app

## Compilation

`gcc -g3 financial_manager.c functions.c -o prog`

## Run

./prog

## Useful functions

- sprintf(property , "format", string_value);
- snprintf();
- strcpy(dst, src);

`sprintf(trans[*count].transports, "%c", '0');`

`strcpy(depenses[i].aliments, depenses[i + 1].aliments);`
`strcpy(depenses[i].transports, depenses[i + 1].transports);`

```
    for (int i=0; i < count; i++)
    {
        printf("%d.", i + 1);
        if (depenses[i].aliments[0] != '\0') {
            printf("aliments: %s\n", depenses[i].aliments);
        }
        if (depenses[i].transports[0] != '\0') {
            printf("transports: %s\n", depenses[i].transports);
        }
    }
```

## Converter

string to float (no risk with int value !)

- atof

string to int

- atoi

```
    float total_aliments = 0;
    float total_transports = 0;

    for (int i=0; i < count; i++)
    {
        printf("%d.", i + 1);
        if (depenses[i].aliments[0] != '\0') {
            printf("aliments: %s\n", depenses[i].aliments);
            total_aliments += atof(depenses[i].aliments); // atof
        }
        if (depenses[i].transports[0] != '\0') {
            printf("transports: %s\n", depenses[i].transports);
            total_transports += atof(depenses[i].transports); // atof
        }
    }
    printf("[+] Total aliments: %.2f\n", total_aliments); // %.2f
    printf("[+] Total transports: %.2f\n", total_transports);
```

---

## sleep()

#include <unistd.h>

sleep(x);