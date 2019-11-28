<!-- # Ooad_project
Designed for Linux/Mac Only. Not yet developed for windows users.</br>
To run the program just execute the start bash file.
```./start```
 -->
 # CC Basket - Online Delivery System
![OOAD Project](https://img.shields.io/badge/Project-OOAD-yellowgreen)
![C++](https://img.shields.io/badge/Language-C%2B%2B-orange)
![build passing](https://api.travis-ci.org/klugjo/hexo-autolinker.svg?branch=master)
![IITJ](https://img.shields.io/badge/Institute-IITJ-yellow)
![2022](https://img.shields.io/badge/Batch-2022-blue)

This project was developed as a course project for **_Dr. Anand Mishra_**, instructor, **_Object Oriented Analysis and Design_** Course. This project encouraged us to expand our horizon on understanding and applying object oriented analysis and design in real life applications. Also helped us in understanding various complexities and challanges involved in software development.
## Problem Statement
The _Community Centre_ of IIT Jodhpur is far for a walk from the student hostels and faculty residence. This makes it very difficult to go and shop for daily needs especially in the scorching heat of Rajasthan. 
An **online delivery system** needs to be developed. The potential customers of this delivery system are the students and faculty members. There has to be online search of products and the customer should be able to perform **online shopping**. There will be various options available to the customers for completing the **payment**- cash on delivery(**_CoD_**), money wallet(**_CCwallet_**) or **credit** system. The customers can choose their **delivery location** and **delivery slot** as per their convenience.
## Proposed Solution
We have tried to implement the online delivery system through concepts of Object Oriented Programming like **modularity**, **abstraction**, **encapsulation** and **generalisation**.

There are three types of users of the system:**customer**(students/faculty members),**shopkeeper** and **moderator.**
*Moderator* is like an intermediate person co-ordinating between shopkeepers,customers and delivery boys.

**_To be edited:_**
Classes and their description:
1) Shopkeeper:
functions:
- constructor: sets a pending amount to zero and gives a shop id.
- login: compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- set_password: stores password entered by the shopkeeper. It is called during registration and edit profile.
- get_details : inputs data required for registration/edit profile.

2) Shop:
functions:
- constructor: provides a shop ID.
- get_details: inputs data required for registration of shop.
- add_items: creates new item and stores in the database.

3)Customer:
functions:
- constructor: initializes credit_balance, wallet balance, number of items in cart and transactions done to zero.
- login: compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- get_details : inputs data required for registration/edit profile.
- add_cart: adds the items selected by the customer to the cart.

### User Registeration
Users(customer/shopkeeper) can register in the portal. Registration requires the following details of the users:
#### Customer 
- Email
- Name
- Contact number
- Password
#### Shopkeeper 
- Email
- Name
- Contact number
- Name of shop
- Password
- Account number
- IFSC code
- Bank Name
- Shop description

Email for both shopkeepers and customers can be of IITJ domain only. No emails with other domains are allowed to register. This is to make sure that people only in IIT Jodhpur can use the portal serivce. We have implemented __________________________ for **verification** of email id and contact number through **_OTP_**. 

There are some rules defined for setting password. User also has to agree to some **_terms and conditions_** (defined separately for shopkeepers and customers) to get registered.
#### Login
Logging into the system requires email and password to be entered. 
Moderator is given a separate email id (of IITJ domain only).

We have implemented C++ functions for authentication of emaild id and password.
#### After Login
##### Customer Login

### Running the Code
Code is written on a Linux Machine, (**ubuntu 18.04**), and we have used various Linux Machine Commands used, e.g., for password input we have used stty linux command, hence the code might not run on other platforms.

To run the code execute 

