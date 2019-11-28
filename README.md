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

This project was developed as a course project for **_Dr. Anand Mishra_**, instructor, **_Object Oriented Analysis and Design_** Course. This project encouraged us to expand our horizon on understanding and applying object oriented analysis and design in real life applications. 
## Problem Statement
The _Community Centre_ of IIT Jodhpur is far for a walk from the student hostels and faculty residence. This makes it very difficult to go and shop for daily needs especially in the scorching heat of Rajasthan. 
An **online delivery system** needs to be developed. The potential customers of this delivery system are the students and faculty members. There has to be online search of products and the customer should be able to perform **online shopping**. There will be various options available to the customers for completing the **payment**- cash on delivery(**_CoD_**), money wallet(**_CCwallet_**) or **credit** system. The customers can choose their **delivery location** and **delivery slot** as per their convenience.
## Proposed Solution
We have tried to implement the online delivery system through concepts of Object Oriented Programming like **modularity**, **abstraction**, **encapsulation** and **generalisation**.

There are three types of users of the system:**customer**(students/faculty members),**shopkeeper** and **moderator.**
*Moderator* is like an intermediate person co-ordinating between shopkeepers,customers and delivery boys.
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

Email for both shopkeepers and customers can be of IITJ domain only. No emails with other domains are allowed to register. This is to make sure that people only in IIT Jodhpur can use the portal serivce.
There are some rules defined for setting password.
#### Login
Logging into the system requires email and password to be entered. 

Moderator is given a separate email id (of IITJ domain only)
