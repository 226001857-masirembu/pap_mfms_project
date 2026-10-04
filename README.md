

# pap_mfms_project

**Municipal Financial Management System (MFMS)**

**Group:** 7

## Group Members

-   Andrias
-   Jonas
-   Chiedza
-   Jeremiah
-   Vistorino
-   Inenecia
-   Selwyn

## Project Description

The Municipal Financial Management System (MFMS) is a C-based system
designed to manage municipal financial information. The system manages
employee, budget, supplier and asset recrds and generates reports based
on the stored infomation.

## System Features

-   **Employee Management:** Add, display and search employee records
    and calculate salary information.
-   **Budget Management:** Record budgets and expenditure, calculate
    remaining funds and identify exceeded budgets.
-   **Supplier Management:** Add, display and search supplier records.
-   **Asset Management:** Add, display and search asset records.
-   **Reports:** Generate employee, budget, supplier, asset and summary
    reports.
-   **Input Validation:** Handle invalid menu choices, invalid numeric
    input and inappropriate values where implemented.

## Technologies

-   C programming language 
-   GCC compiler
-   GitHub

## Compile

The complete system was compiled using GCC with the C99 standard and
warning flags:

The final project compiled successfully with minil no compiler errors.

## Run

On Windows:

``` bash
mfms.exe
```

## Responsibilities

-   **Andrias** --- Employee Management
-   **Jonas** --- Functions, integration and validation
-   **Chiedza** --- Testing, documentation and Git coordination
-   **Inenecia** --- Budget Management
-   **Vistorino** --- Supplier Management
-   **Jeremiah** --- Asset Management
-   **Selwyn** --- Reports

## Testing

The integrated MFMS was tested across the main menu, Employee
Management, Budget Management, Supplier Management, Asset Management and
Reports modules.

Testing included:

-   Valid module operations
-   Invalid main menu input
-   Invalid numeric input
-   Negative salary validation
-   Negative budget validation
-   Negative asset vaue validation
-   Supplier search
-   Budget search
-   Reports
-   Over-budget detectio
-   System exit
-   Full project compilation and integration

A total of 24 tests were recorded. The final test results and supporting
evidence are documented in `testing/test_results.md`.

Two known validation limitations were identified during testing:

1.  The Employee module currently accepts a negative basic salary.
2.  The Supplier module curretly accepts a blank supplier name.

These are documented as known limitations and recommended future
improvements.

## Contributions

Individual contribution records are in the `contributions/`
directory.

## Repository

**GitHub Repository:**
https://github.com/226001857-masirembu/pap_mfms_project



