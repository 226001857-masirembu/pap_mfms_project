# MFMS Test Results

Integration Review – Reports Module

During review of the Reports module, compatibility differences were identified between the report functions and the Supplier/Asset data structures. The Reports module currently expects parallel arrays, while the Supplier and Asset modules use structures.



## Employee ##

<img width="655" height="197" alt="image" src="https://github.com/user-attachments/assets/2ed8c4d7-8bfb-4c10-a0d8-cb316193d642" />
 successful employee.exe

<img width="318" height="245" alt="image" src="https://github.com/user-attachments/assets/9e9969bb-9b60-4bc0-a7b7-aaf60f05bacc" />
successful  add employee 

 <img width="678" height="441" alt="image" src="https://github.com/user-attachments/assets/bad4bc58-9e6c-4b09-8ded-11a920791437" />

 successful display employee

 <img width="294" height="237" alt="image" src="https://github.com/user-attachments/assets/94773bde-43dd-44c6-af20-828418cd0c9d" />

successful employee search

 <img width="373" height="224" alt="image" src="https://github.com/user-attachments/assets/f0b1e17c-76e0-4753-a127-e169bea94c7a" />

successful calculations of employee salary

## Budgeting ##

## Assets ##

During intial testing, the Asset module was compiled separately using gcc assets.c -o assets. The compilation/linking failed with the error undefined reference to 'WinMain'. This occurred because assets.c does not contain a main() function and is intended to operate as a module within the complete Municipal Financial Management System. To fix this we have to link the asset to the main.c
## Supplier ##

During intial testing, the Supplier module was compiled separately using gcc sipplier.c -o supplier. The compilation/linking failed with the error undefined reference to 'WinMain'. This occurred because supplier.c does not contain a main() function and is intended to operate as a module within the complete Municipal Financial Management System. To fix this we have to link the supplier to the main.c

## Report ##

During intial testing, the Supplier module was compiled separately using gcc report.c -o report. The compilation/linking failed with the error undefined reference to 'WinMain'. This occurred because report.c does not contain a main() function and is intended to operate as a module within the complete Municipal Financial Management System. To fix this we have to link the report to the main.c




## Final Testing Notes

The final results will be updated after the complete system has been compiled, executed and tested.
