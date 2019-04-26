# Commodity Inventory System

The process of using human effort to manually manage inventory is time consuming and prone to human error. Manual inventory tracking wastes useful labour in trivial works. Even programs like Microsoft Excel offer spreadsheets and tables that are not user friendly enough for beginners.

A commodity inventory system which would help in resolving the above problem would be beneficial to the retail shops, as this system increases the efficiency of inventory management by removing human error and extra efforts, hence saving unproductive time.

# Getting Started

## Installation

### Prerequisites

The program is a C++ 11 standard program. It must run in an appropriate C++ 11 Standard compiler. This program will run best  in a Ubuntu (Linux) environment as it is programmed in Ubuntu.

### Building the program

OS X & Linux:

```sh
make main
```

Windows:

```sh
make main
```
or
```sh
mingw32-make main
```
Depending on the version of Make installed in your machine

### Running the program

OS X & Linux:

```sh
./main
```

Windows:

```sh
./main.exe
```
## Data Input and Output Format

Information.txt - the information of each Commodity

Information.txt:
```sh
<Commodity1 Name>,<Commodity1 Category>,<Commodity1 Manufacturer>,<Commodity1 Price>,<Shop1 Name>,<Shop1 Quantity>,<Shop2 Name>,<Shop2 Quantity>,...
<Commodity2 Name>,<Commodity2 Category>,<Commodity2 Manufacturer>,<Commodity2 Price>,<Shop1 Name>,<Shop1 Quantity>,<Shop2 Name>,<Shop2 Quantity>,...
```

Shop.txt - the name of each Shop

Shop.txt:
```sh
<Shop1 Name>,<Shop2 Name>,<Shop3 Name>,<Shop4 Name>,...
```

<Shop Name>_History.txt - the history information of each Shop

<Shop Name>_History.txt:
```sh
<Date1>;Recorded at time:<Time1>
<History Data>
;
```

## Basic Features

* Search commodity according to different filters (e.g. in-stock/out-of-stock)
* Insert new commodity with basic information (name, manufacturer, amount, price, availability of shop(s)) after each procurement 
* Delete obsolete commodity 
* Update commodity information 
* Automatic change of inventory status according to the amount of commodity that is currently available (e.g. when the amount reaches     zero, the inventory status would become “out-of-stock”); 
* Deliver alerts when the commodity is “out-of-stock”


## Additional Features 

* Removal of duplicate commodities (Barcode ID can be implemented)
* Import/export full inventory list to local file (.txt)
* Sales/purchases history (Sorted by timestamps) 

## Contributors

* Chua Qian Yi (3035604439)
* Lim Le Chi (30355549249)
