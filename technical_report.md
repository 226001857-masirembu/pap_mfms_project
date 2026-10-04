# Municipal Financial Management System

## Technical Report

### Group 7

------------------------------------------------------------------------

## 1. Introduction

The Municipal Financial Management System (MFMS) is a C-based system
designed to assist with the management of municipal financial
information.

The system manages employee, budget, supplier and asset information and
provides reports based on these records.

The project was developed collaboratively using GitHub for source-code
management, documentation and team coordination.

------------------------------------------------------------------------

## 2. System Overview

The system consists of several modules, with each module responsible for
a specific area of municipal financial management.

The main modules are:

-   Employee Management
-   Budget Management
-   Supplier Management
-   Asset Management
-   Reports
-   Main Program and Integration

The modules are integrated through the main program and operate together
as one system.

------------------------------------------------------------------------

## 3. System Design

The system was implemented in C using a modular structure. Each major
area of functionality is separated into its own source and header
 files.

### 3.1 Employee Management

The Employee module manages employee records and allows users to add,
display and search employee information. It also calculates gross salary
from the basic salary and allowances.

### 3.2 Budget Management

The Budget module manages municipal budget information. It records
allocated budgets and expenditure, calculates remaining funds and
identifies departments whose expenditure exceeds their allocation.

### 3.3 Supplier Management

The Supplier module manages supplier records. Users can add, display and
search supplier information using supplier ID or name.

### 3.4 Asset Management

The Asset module manages municipal asset records. Users can add, display
and search asset information. Purchse values are checked to prevent
negative values.

### 3.5 Reports

The Reports module provides employee, budget, supplier, asset and
summary reports. These reports present stored information and calculated
totals.

### 3.6 Main Program and Integration

The main program provides the user interface and connects the different
modules. It handles the main menu, module navigation and shared input
validation.

------------------------------------------------------------------------

## 4. Implementation

The system was implemented using the C programming language and follows
a modular structure.

The project uses separate source (`.c`) and header (`.h`) files for the
Employee, Budget, Supplier, Asset and Reports modules. The main program
handles menu navigation and integration between the modules.

The project was compiled using GCC with the C99 standard and warning
flags:

``` bash
gcc -std=c99 -Wall -Wextra main.c employee.c budget.c suppliers.c assets.c reports.c -o mfms
```

The complete project compiled successfully with no compiler errors or
warnings.

------------------------------------------------------------------------

## 5. Input Validation

Input validation was implemented throughout the system to handle invalid
menu choices, non-numeric input and inappropriate values.

The Budget module rejects negative allocated budget and expenditure
values. The Asset module rejects negative purchase values. The main
program also provides shared validation for numeric input and non-empty
strings.

During final testing, two validation limitations were identified. The
Employee module accepted a negative basic salary, and the Supplier
module accepted a blank supplier nae. These issues were recorded as
failed tests and are recommended for future improvement.

------------------------------------------------------------------------

## 6. Testing

The completed MFMS was tested after integration.

Testing covered:

-   Main menu and navigation
-   Employee Management
-   Budget Management
-   Supplier Management
-   Asset Management
-   Reports
-   Invalid numeric input
-   Negative salary, budget and asset values
-   Supplier search
-   Budget search
-   Over-budget detection
-   System exit
-   Full project compilation and integration

A total of 24 tests were recorded. The final test results document the
expected result, actual result and PASS/FAIL status for each test.

Most functional and validation tests passed. Two validation tests
failed:

1.  **Negative basic salary:** The Employee module accepted a negative
    basic salary.
2.  **Empty supplier name:** The Supplier module accepted a blank
    supplier name.

These limitations were documened rather than making last-minute changes
to the integrated system.

Supporting screenshots are included in the testing evidence where
available.

------------------------------------------------------------------------

## 7. GitHub Collaboration

GitHub was used to manage the group's source code, documentation and
contribution records.

The repository contains the project's source code, documentation,
testing information and individual contribution records.

Each group member was assigned specific responsibilities within the
project, and contribution evidence was maintained through the repository
and contribution records.

------------------------------------------------------------------------

## 8. Challenges and Solutions

Several integration and development challenges were encountered during
the project.

One major challenge involved compilation and integration of the Budget
module. The module initially contained compilation and implementation
issues. The Budget source and header files were corrected and the module
was successfully complied.

Another challenge involved integrating independently developed modules
into the main program. The modules were linked through the main program
and tested as a complete system.

Testing also identified validation limitations involving negative
employee salaries and blank supplier names. These were recorded as known
issues and recommended for future improvement.

------------------------------------------------------------------------

## 9. Testing Results

Final system testing was completed after integration.

The complete system successfully launched, displayed the main menu,
navigated between modules, processed valid records and generated
reports.

The final testing record contains 24 tests covering compilation,
navigation, module functionality, reports, inpu validation, searching,
over-budget detection and system exit.

Two validation tests failed:

-   Negative employee salary validation
-   Blank supplier name validation

These known limitations are documented in `testing/test_results.md`,
together with the expected and actual outcomes and supporting evidence.

------------------------------------------------------------------------

## 10. Conclusion

The Municipal Financial Management System provides a modular C-based
approach to managing municipal financial information.

The completed system integrates employee, budget, supplier, asset and
reporting functionality into one application.

Final testing confirmed that the main functionality operates
successfully, while the identified validation limitations have been
documented as areas for future improvement.
