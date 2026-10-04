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

<img width="791" height="230" alt="test_03_main_menu" src="https://github.com/user-attachments/assets/c2a2364b-0ff7-4888-bcbb-16f292e56270" />


## Test 4 --- Invalid main-menu choice (9)

 The system rejected 9, displayed an error,
and returned to the main menu.

**Result:** **PASS**

The system correctly rejected an invalid main menu
choice of 9, displayed an appropriate error message, and returned to the
main menu.

**Evidence:**

<img width="310" height="200" alt="test_04_invalid_main_menu" src="https://github.com/user-attachments/assets/66ab0df3-910b-4cef-9703-6d1bdfc54f3d" />


## Test 5 --- Employee Management
 Employee Management opened and its
functions were tested successfully.

**Result:** **PASS**

 The Employee Management module opened successfully
and its available functions were accessible and tested.

<img width="655" height="197" alt="image" src="https://github.com/user-attachments/assets/2ed8c4d7-8bfb-4c10-a0d8-cb316193d642" />
 successful employee.exe

<img width="318" height="245" alt="image" src="https://github.com/user-attachments/assets/9e9969bb-9b60-4bc0-a7b7-aaf60f05bacc" />
successful  add employee 

 <img width="678" height="441" alt="image" src="https://github.com/user-attachments/assets/bad4bc58-9e6c-4b09-8ded-11a920791437" />

 successful display employee

 <img width="294" height="237" alt="image" src="https://github.com/user-attachments/assets/94773bde-43dd-44c6-af20-828418cd0c9d" />


## Test 6 --- Add Budget

 Finance, N\$4000, was added successfully.

**Result:** **PASS**

 \> The Budget Management module successfully accepted a
valid department and allocated budget of N\$4,000 and confirmed that the
budget was added successfully.

**Evidence:**

<img width="308" height="344" alt="test_06_add_budget" src="https://github.com/user-attachments/assets/e380898a-aa92-4096-8fb7-3973bb399a43" />


## Test 7 --- Display Budgets

The stored Finance budget was displayed
correctly.

**Result:** **PASS**

  The system successfully displayed the stored Finance
budget and its associated budget information.

**Evidence:**

<img width="673" height="649" alt="image" src="https://github.com/user-attachments/assets/de6be46d-5025-40ec-a35c-b559b45b2d68" />


## Test 8 --- Budget search miss

 A non-existent department returned
'Department budget not found.'

**Result:** **PASS**

The system correctly reported that the department
budget was not found.

**Evidence:**

<img width="301" height="217" alt="test_08_budget_search_miss" src="https://github.com/user-attachments/assets/d010acb1-5b01-4123-bdcf-c68994f4f109" />

## Test 9 --- Add Supplier

Supplier ID 56 (Saul) was added
successfully.

**Result:** **PASS**

 The Supplier Management module successfully added
the supplier and confirmed the operation.

**Evidence:**

<img width="305" height="344" alt="test_09_supplier_add" src="https://github.com/user-attachments/assets/0e04ab37-f056-420e-8fc8-d2f5b8b2a4f1" />


## Test 10 --- Search Supplier

**Expected/observed result:** Supplier ID 56 was found and details
displayed.

**Result:** **PASS**

 The system successfully searched for supplier ID 56
and displayed the stored supplier details.

**Evidence:**

<img width="277" height="199" alt="test_10_supplier_search" src="https://github.com/user-attachments/assets/8fbf690e-7230-4f2b-afba-99b964922d44" />

## Test 11 --- Add Asset

 Asset ID 78 (Car), N\$35000, was added
successfully.

**Result:** **PASS**

The Asset Management module successfully added the
asset and confirmed the operation.

**Evidence:**

<img width="310" height="343" alt="test_11_asset_add" src="https://github.com/user-attachments/assets/d93151c2-9843-4fdb-8adf-ddd31b42da1b" />


## Test 12 --- Display Assets

Asset ID 78 and its details were
displayed.

**Result:** **PASS**

 The system successfully displayed the stored asset
details.

**Evidence:**

<img width="248" height="221" alt="test_12_asset_display" src="https://github.com/user-attachments/assets/6f1b45b9-fadd-45b2-8cb5-98bdb5cf073e" />


## Test 13 --- Budget Report

**Expected/observed result:** Budget totals and Finance details were
displayed.

**Result:** **PASS**

 The Budget Report successfully displayed the stored
budget totals and Finance department details.

<img width="337" height="325" alt="test_13_budget_report" src="https://github.com/user-attachments/assets/ee0c312a-4247-4984-9a9e-082fd57f89f0" />


## Test 14 --- Supplier Report

**Expected/observed result:** One supplier and its stored details were
displayed.

**Result:** **PASS**

 The Supplier Report successfully displayed the
stored supplier information and total supplier count.

**Evidence:**

<img width="305" height="292" alt="test_14_supplier_report" src="https://github.com/user-attachments/assets/943ec46e-0501-4437-919d-2f7799fe3401" />


## Test 15 --- Asset Report

 Asset ID 78 and its details were
displayed.

**Result:** **PASS**

The Asset Report successfully displayed the stored
asset details.

<img width="538" height="595" alt="image" src="https://github.com/user-attachments/assets/ca79195d-5ec3-4579-ae24-29cab2dde27c" />


## Test 16 --- Summary Report

**Expected/observed result:** The Summary Report was generated
successfully.

**Result:** **PASS**

The Summary Report was generated successfully using
the available system data.

## Test 17 --- Invalid non-numeric input

**Expected/observed result:** The system displayed 'Invalid input.
Please enter a number:'

**Result:** **PASS**

 The system correctly detected non-numeric input and
displayed an appropriate validation message requesting a numeric value.

**Evidence:**

<img width="742" height="585" alt="image" src="https://github.com/user-attachments/assets/7fc2bca1-967a-400b-a8df-a4bdda9ded33" />

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

<img width="270" height="227" alt="test_18_expenditure_update" src="https://github.com/user-attachments/assets/7809375f-a8c9-479c-9072-d5e861339bf3" />


## Test 19 --- Over-budget detection

**Expected/observed result:** Finance was identified as exceeded after
N\$5000 expenditure against N\$4000 allocated.

**Result:** **PASS**

 The system correctly identified and displayed the
Finance budget as exceeded.

<img width="1672" height="941" alt="image" src="https://github.com/user-attachments/assets/9568a73b-6f1d-4acf-b812-8eeb9cee818e" />

## Test 20 --- Negative salary validation

**Expected/observed result:** The system accepted a basic salary of
N\$-5000.

**Result:** **FAIL**

FAIL --- The system accepted a negative basic salary
of N\$-5,000 instead of rejecting the value. This is a known limitation
for future improvement.

**Evidence:**

<img width="285" height="309" alt="test_20_negative_salary_FAIL" src="https://github.com/user-attachments/assets/f7e54565-a404-4bad-abb9-a594c559d744" />


## Test 21 --- Negative budget validation

**Expected/observed result:** N\$-5000 was rejected with a
negative-value message.

**Result:** **PASS**

 The system rejected a negative allocated budget of
N\$-5,000 and prompted the user to enter a valid non-negative value.

**Evidence:**

<img width="293" height="218" alt="test_21_negative_budget" src="https://github.com/user-attachments/assets/ceabe39d-4de5-4fe2-b552-8b713e6026b2" />


## Test 22 --- Negative asset purchase value

**Expected/observed result:** N\$-1000 was rejected.

**Result:** **PASS**

 The system rejected a negative asset purchase value
of N\$-1,000 and displayed an appropriate validation message.

**Evidence:**
<img width="262" height="159" alt="test_22_negative_asset_value" src="https://github.com/user-attachments/assets/1748f1dd-c65f-4bb7-b1d5-584a1376071e" />


## Test 23 --- Empty supplier name

**Expected/observed result:** A blank supplier name was accepted.

**Result:** **FAIL**

FAIL --- The system accepted a supplier with a blank
name instead of rejecting the empty input. This is a known limitation
for future improvement.

**Evidence:**

<img width="253" height="170" alt="test_23_blank_supplier_name_FAIL" src="https://github.com/user-attachments/assets/1c6d4f2b-75c2-493c-bba4-a804c2ae79c1" />


## Test 24 --- Exit option
 The program displayed 'Exiting system...'
and returned to PowerShell.

**Result:** **PASS**

 The Exit option successfully terminated the MFMS
application and returned control to the command-line environment.

**Evidence:**

<img width="719" height="176" alt="test_24_exit" src="https://github.com/user-attachments/assets/a5c4e1e1-f8d4-4df7-a5fd-01aba59c4063" />


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

