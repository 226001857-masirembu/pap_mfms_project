# MFMS Test Results

## PAP521S --- Municipal Financial Management System

This document records the final functional and validation testing
performed on the MFMS application. Screenshots are stored in
`mfms_test_evidence/` and referenced below where available.

## Test 1 --- Budget-only compilation

 Budget module compiled successfully with
no errors or warnings.

**Result:** **PASS**

 The Budget module compiled successfully with no
errors or warnings.

<img width="1390" height="885" alt="image" src="https://github.com/user-attachments/assets/77544660-80c4-4331-9d26-98d9120ab238" />

<img width="1339" height="142" alt="image" src="https://github.com/user-attachments/assets/046cac7a-fb01-4270-89aa-934ff7476020" />


## Test 2 --- Full project compilation

 All project source files compiled and
mfms.exe was created.

**Result:** **PASS**

 The complete MFMS project compiled successfully with
no errors or warnings, and mfms.exe was created.

**Evidence:**

![Test 2 --- Full project
compilation](mfms_test_evidence/test_02_full_compilation.png)

## Test 3 --- MFMS launch and main menu

The executable launched and displayed all
required modules and Exit.

**Result:** **PASS**
\> The MFMS executable launched successfully and
displayed the complete main menu with all required modules and the Exit
option.

**Evidence:**

![Test 3 --- MFMS launch and main
menu](mfms_test_evidence/test_03_main_menu.png)

## Test 4 --- Invalid main-menu choice (9)

 The system rejected 9, displayed an error,
and returned to the main menu.

**Result:** **PASS**

The system correctly rejected an invalid main menu
choice of 9, displayed an appropriate error message, and returned to the
main menu.

**Evidence:**

![Test 4 --- Invalid main-menu choice
(9)](mfms_test_evidence/test_04_invalid_main_menu.png)

## Test 5 --- Employee Management
 Employee Management opened and its
functions were tested successfully.

**Result:** **PASS**

 The Employee Management module opened successfully
and its available functions were accessible and tested.

**Evidence:** Screenshot captured during the testing session; no local
image file was available for this generated GitHub package.

## Test 6 --- Add Budget

 Finance, N\$4000, was added successfully.

**Result:** **PASS**

 \> The Budget Management module successfully accepted a
valid department and allocated budget of N\$4,000 and confirmed that the
budget was added successfully.

**Evidence:**

![Test 6 --- Add Budget](mfms_test_evidence/test_06_add_budget.png)

## Test 7 --- Display Budgets

The stored Finance budget was displayed
correctly.

**Result:** **PASS**

  The system successfully displayed the stored Finance
budget and its associated budget information.

**Evidence:**

![Test 7 --- Display
Budgets](mfms_test_evidence/test_07_display_budget.png)

## Test 8 --- Budget search miss

 A non-existent department returned
'Department budget not found.'

**Result:** **PASS**

The system correctly reported that the department
budget was not found.

**Evidence:**

![Test 8 --- Budget search
miss](mfms_test_evidence/test_08_budget_search_miss.png)

## Test 9 --- Add Supplier

Supplier ID 56 (Saul) was added
successfully.

**Result:** **PASS**

 The Supplier Management module successfully added
the supplier and confirmed the operation.

**Evidence:**

![Test 9 --- Add Supplier](mfms_test_evidence/test_09_supplier_add.png)

## Test 10 --- Search Supplier

**Expected/observed result:** Supplier ID 56 was found and details
displayed.

**Result:** **PASS**

 The system successfully searched for supplier ID 56
and displayed the stored supplier details.

**Evidence:**

![Test 10 --- Search
Supplier](mfms_test_evidence/test_10_supplier_search.png)

## Test 11 --- Add Asset

 Asset ID 78 (Car), N\$35000, was added
successfully.

**Result:** **PASS**

The Asset Management module successfully added the
asset and confirmed the operation.

**Evidence:**

![Test 11 --- Add Asset](mfms_test_evidence/test_11_asset_add.png)

## Test 12 --- Display Assets

Asset ID 78 and its details were
displayed.

**Result:** **PASS**

 The system successfully displayed the stored asset
details.

**Evidence:**

![Test 12 --- Display
Assets](mfms_test_evidence/test_12_asset_display.png)

## Test 13 --- Budget Report

**Expected/observed result:** Budget totals and Finance details were
displayed.

**Result:** **PASS**

 The Budget Report successfully displayed the stored
budget totals and Finance department details.

**Evidence:** Screenshot captured during the testing session; no local
image file was available for this generated GitHub package.

## Test 14 --- Supplier Report

**Expected/observed result:** One supplier and its stored details were
displayed.

**Result:** **PASS**

 The Supplier Report successfully displayed the
stored supplier information and total supplier count.

**Evidence:**

![Test 14 --- Supplier
Report](mfms_test_evidence/test_14_supplier_report.png)

## Test 15 --- Asset Report

 Asset ID 78 and its details were
displayed.

**Result:** **PASS**

The Asset Report successfully displayed the stored
asset details.

**Evidence:** Screenshot captured during the testing session; no local
image file was available for this generated GitHub package.

## Test 16 --- Summary Report

**Expected/observed result:** The Summary Report was generated
successfully.

**Result:** **PASS**

The Summary Report was generated successfully using
the available system data.

**Evidence:** Screenshot captured during the testing session; no local
image file was available for this generated GitHub package.

## Test 17 --- Invalid non-numeric input

**Expected/observed result:** The system displayed 'Invalid input.
Please enter a number:'

**Result:** **PASS**

 The system correctly detected non-numeric input and
displayed an appropriate validation message requesting a numeric value.

**Evidence:**

![Test 17 --- Invalid non-numeric
input](mfms_test_evidence/test_17_invalid_numeric_input.png)

## Test 18 --- Enter Expenditure

 Finance expenditure was updated to
N\$5000.

**Result:** **PASS**

 The system successfully updated the Finance
department expenditure to N\$5,000 against an allocated budget of
N\$4,000.

**Evidence:**

![Test 18 --- Enter
Expenditure](mfms_test_evidence/test_18_expenditure_update.png)

## Test 19 --- Over-budget detection

**Expected/observed result:** Finance was identified as exceeded after
N\$5000 expenditure against N\$4000 allocated.

**Result:** **PASS**

 The system correctly identified and displayed the
Finance budget as exceeded.

**Evidence:** Screenshot captured during the testing session; no local
image file was available for this generated GitHub package.

## Test 20 --- Negative salary validation

**Expected/observed result:** The system accepted a basic salary of
N\$-5000.

**Result:** **FAIL**

FAIL --- The system accepted a negative basic salary
of N\$-5,000 instead of rejecting the value. This is a known limitation
for future improvement.

**Evidence:**

![Test 20 --- Negative salary
validation](mfms_test_evidence/test_20_negative_salary_FAIL.png)

## Test 21 --- Negative budget validation

**Expected/observed result:** N\$-5000 was rejected with a
negative-value message.

**Result:** **PASS**

 The system rejected a negative allocated budget of
N\$-5,000 and prompted the user to enter a valid non-negative value.

**Evidence:**

![Test 21 --- Negative budget
validation](mfms_test_evidence/test_21_negative_budget.png)

## Test 22 --- Negative asset purchase value

**Expected/observed result:** N\$-1000 was rejected.

**Result:** **PASS**

 The system rejected a negative asset purchase value
of N\$-1,000 and displayed an appropriate validation message.

**Evidence:**

![Test 22 --- Negative asset purchase
value](mfms_test_evidence/test_22_negative_asset_value.png)

## Test 23 --- Empty supplier name

**Expected/observed result:** A blank supplier name was accepted.

**Result:** **FAIL**

FAIL --- The system accepted a supplier with a blank
name instead of rejecting the empty input. This is a known limitation
for future improvement.

**Evidence:**

![Test 23 --- Empty supplier
name](mfms_test_evidence/test_23_blank_supplier_name_FAIL.png)

## Test 24 --- Exit option

**Expected/observed result:** The program displayed 'Exiting system...'
and returned to PowerShell.

**Result:** **PASS**

 The Exit option successfully terminated the MFMS
application and returned control to the command-line environment.

**Evidence:**

![Test 24 --- Exit option](mfms_test_evidence/test_24_exit.png)

## Recommended Improvements / Future Improvements

1.  **Negative salary validation:** Reject negative salary values and
    prompt the user for a valid non-negative salary.
2.  **Blank supplier name validation:** Prevent suppliers from being
    added with blank names and prompt the user for a valid supplier
    name.

## Final Testing Conclusion

The MFMS project compiled successfully and the major functional modules,
navigation, reporting features and most validation requirements were
successfully tested. Two validation limitations were identified:
negative salary values are accepted and blank supplier names are
accepted. These were documented as known limitations for future
improvement due to the project deadline.

