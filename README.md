 # CC Basket - Online Delivery System
![OOAD Project](https://img.shields.io/badge/Project-OOAD-yellowgreen)
![C++](https://img.shields.io/badge/Language-C%2B%2B-orange)
![build passing](https://api.travis-ci.org/klugjo/hexo-autolinker.svg?branch=master)
![IITJ](https://img.shields.io/badge/Institute-IITJ-yellow)
![2022](https://img.shields.io/badge/Batch-2022-blue)

This project was developed as a course project for **_Dr. Anand Mishra_**, instructor, **_Object Oriented Analysis and Design_** Course. This project encouraged us to expand our horizon on understanding and applying object oriented analysis and design in real life applications. It also helped us in understanding various complexities and challanges involved in software development.
## Problem Statement
The _Community Centre_ of IIT Jodhpur is far for a walk from the student hostels and faculty residence. This makes it very difficult to go and shop for daily needs especially in the scorching heat of Rajasthan. 
An **online delivery system** needs to be developed. The potential customers of this delivery system are the students and faculty members. There has to be online search of products and the customer should be able to perform **online shopping**. There will be various options available to the customers for completing the **payment**- cash on delivery(**_CoD_**), money wallet(**_CCwallet_**) or **credit** system. 
## Proposed Solution
We have tried to implement the online delivery system through concepts of Object Oriented Programming like **modularity**, **abstraction**, **encapsulation** and **generalisation**.

We have implemented **_database_** by using exccessive **file handling** in C++. We have also used **exception handling**.

We have implemented a feature using _______________ which sends an **email** to registered users regarding **_holiday declaration_** with a custom message. 

There are three types of users of the system:**customer**(students/faculty members),**shopkeeper** and **moderator.**
*Moderator* is like an intermediate person co-ordinating between shopkeepers,customers and delivery boys.


### Classes and their functions description:
1. Shopkeeper
Functions:
- constructor: sets a pending amount to zero and gives a shop id.
- login: compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- set_password: stores password entered by the shopkeeper. It is called during registration and edit profile.
- get_details : inputs data required for registration/edit profile.

2. Shop
Functions:
- constructor: provides a shop ID.
- get_details: inputs data required for registration of shop.
- add_items: creates new item and stores in the database.

3. Customer:
Functions:
- constructor: initializes credit_balance, wallet balance, number of items in cart and transactions done to zero.
- login: compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- get_details : inputs data required for registration/edit profile.
- add_cart: adds the items selected by the customer to the cart.
- select_items: co-ordinates displaying items and adding to cart and returns the final transaction details.

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
### Login
Logging into the system requires email and password to be entered. 
Moderator is given a separate email id (of IITJ domain only).

We have implemented C++ functions for authentication of emaild id and password.
### After Login
#### Customer Login
A screen is displayed with different actions to choose from like shopping,viewing transcation history,view and edit profile ,logout etc. For shopping, names of various shops is displayed and on selecting a shop, products of that shops are displayed; a search option
which works on basis of keyword matching is also present. The customer would have to enter quantity of items after searching the items. These items with their quantity are added to the cart.After shopping, the customer has to proceed to checkout and proceed for payment thereafter. On selecting the cart,order summary and total amount is visible with an option to checkout.
#### Shopkeeper Login
A screen is displayed with different actions to choose from such as viewing and editing profile, updating and adding shop items, view transaction history,etc. 

The shopkeeper has the option to view his profile and edit his deltails. In option of adding items to the shop, he can add altogether new items apart from the existing ones. Updating items allows shopkeeper to update the name or quantity of the existing items. He can also view his monetory transaction history upto the present date.
## Running the Code
Code is written on a Linux Machine, (**ubuntu 18.04**), and we have used various Linux Machine Commands, e.g., for password input we have used **_stty_** linux command, hence the **code might not run on other platforms**.

Clone into repository
```batch
git clone https://github.com/NiveditJain/Ooad_project    
```
Navigate into repository
```batch
cd Ooad_project
```

To run the code execute 
``` batch
./start
```
This will check all the requirements and tell you in case the requirements are not met. In case all the requirements are met it will start running your code.

However you can also follow the following instructions to install all the requirements.
