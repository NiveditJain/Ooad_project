 # CC Basket - Online Delivery System
![system requirements](https://img.shields.io/badge/g%2B%2B%20Version-7.4.0-red)
![system requirements](https://img.shields.io/badge/Python-3.6.8-orange)
![system requirements](https://img.shields.io/badge/OS-Ubuntu%2018.04.1-yellow)
![OOAD Project](https://img.shields.io/badge/Project-OOAD-yellowgreen)
![C++](https://img.shields.io/badge/Language-C%2B%2B-orange)
![build passing](https://api.travis-ci.org/klugjo/hexo-autolinker.svg?branch=master)
![IITJ](https://img.shields.io/badge/Institute-IITJ-yellow)
![2022](https://img.shields.io/badge/Batch-2022-blue)

This project was developed as a course project for **_Dr. Anand Mishra_**, instructor, **_Object Oriented Analysis and Design_** Course. This project encouraged us to expand our horizon on understanding and applying object oriented analysis and design in real life applications. It also helped us in understanding various complexities and challanges involved in software development.
## Problem Statement
The _Community Centre_ of IIT Jodhpur is far for a walk from the student hostels and faculty residence. This makes it very difficult to go and shop for daily needs especially in the scorching heat of Rajasthan. 
An **online delivery system** needs to be developed. The potential customers of this delivery system are the students and faculty members. There has to be online search of products and the customer should be able to perform **online shopping**. There will be various options available to the customers for completing the **payment**- cash on delivery(**_CoD_**) or **credit** system. 
## Proposed Solution
We have tried to implement the online delivery system through concepts of Object Oriented Programming like **modularity**, **abstraction**, **encapsulation** and **generalisation**.

We have implemented **_database_** by using exccessive **file handling** in C++. We have also used **exception handling**.

We have implemented a feature using **SMTP python3 library** which sends an **email** to registered users regarding **_holiday declaration_** with a custom message. 

There are three types of users of the system:**customer**(students/faculty members),**shopkeeper** and **moderator.**
*Moderator* is like an intermediate person co-ordinating between shopkeepers,customers and delivery boys.


### Significant classes and their functions description:
**1.** **Shopkeeper functions:**
- **constructor:** sets a pending amount to zero and gives a shop id.
- **login:** compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- **set_password:** stores password entered by the shopkeeper. It is called during registration and edit profile.
- **get_details :** inputs data required for registration/edit profile.

**2. Shop functions:**
- **constructor:** provides a shop ID.
- **get_details:** inputs data required for registration of shop.
- **add_items:** creates new item and stores in the database.

**3. Customer functions:**
- **constructor:** initializes credit_balance, wallet balance, number of items in cart and transactions done to zero.
- **login:** compares the password entered by the shopkeeper with the password that is in the database and returns true/false.
- **get_details:** inputs data required for registration/edit profile.
- **add_cart:** adds the items selected by the customer to the cart.
- **select_items:** co-ordinates displaying items and adding to cart and returns the final transaction details.

**4. Moderator functions:**
- **login:** authenticates password.
- **get_customer_mails:** retrieving customer emails to send holiday mail.
- **get_shopkeeper_mails:** retrieving shopkeeper emails to send holiday mail.
- **mail_holiday:** triggers sending email for holiday.
- **mail_vacation:** triggers sending email for vacation.
- **assign_delivery_boy:** assigning delivery boy for delivery.
- **update_password:** enables moderator to change/update password.

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

Email for both shopkeepers and customers can be of IITJ domain only. No emails with other domains are allowed to register. This is to make sure that people only in IIT Jodhpur can use the portal serivce. We have implemented **SMTP python3 library** for **verification** of email id through **_OTP_** and **Fast2 SMS API** for contact number verification through **_OTP_**. 

There are some rules defined for setting password. User also has to agree to some **_terms and conditions_** (defined separately for shopkeepers and customers) to get registered.
### Login
Logging into the system requires email and password to be entered. 
Moderator is given a separate email id (of IITJ domain only) and a predefined password. He can change/update the password anytime he wants.

We have implemented C++ functions for authentication of emaild id and password.
### After Login
#### Customer Login
A screen is displayed with different actions to choose from like shopping,viewing transcation history,view and edit profile ,logout etc. For shopping, names of various shops is displayed and on selecting a shop, products of that shops are displayed; customer would have to select items for shopping and then would have to enter quantity of items. These items with their quantity are added to the cart.After shopping, the customer has to proceed to checkout and proceed for payment thereafter. On selecting the cart,order summary and total amount is visible with an option to checkout.
#### Shopkeeper Login
A screen is displayed with different actions to choose from such as viewing and editing profile, updating and adding shop items, view transaction history,etc. 

The shopkeeper has the option to view his profile and edit his deltails. In option of adding items to the shop, he can add altogether new items apart from the existing ones. Updating items allows shopkeeper to update the name or quantity of the existing items. He can also view his monetory transaction history upto the present date.
#### Moderator Login
A screen with different actions to choose from is displayed. Moderator can send emails declaring holiday or vacation for CC, he can change/update password and edit credit balance of customer.

## Running the Code
Code is written on a Linux Machine, (**ubuntu 18.04**), and we have used various Linux Machine Commands, windows users can run it on WSL Terminal or Windows Terminals or equivalent Linux virtual enviornments, e.g., for password input we have used **_stty_** linux command, hence the **code might not run on other platforms**. Codes were further executed using **g++** compiler and **python3.6**.

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
### g++ Compiler
g++ is worlddwide popular C++ complier can be installed on your linux/macOS by running the following commands.

This installs the core of g++ TMD-GCC compiler
```bash
sudo apt install gcc
```
Then installing additonal functionalities of C++
```bash
sudo apt install g++
```
For testing installation run,
``` bash
g++ -v
```
If this command prints sysem details and version of g++ compiler than it has been installed successfully. 
Output on our system were
```
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.4.0-1ubuntu1~18.04.1' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
```
### Python3
Python3 is usually pre-installed on linux however it may be utdated, upgrade your system to modern verions.<\br>
For updating
```bash
sudo apt-get update
```
For upgrading
```bash
sudo apt-get upgrade python3
```
In case still not install following command can also be runned
```bash
sudo apt-get install python3
```
To check to successfull installation run
```bash
python3 -v
```
Pip also must be installed for package management
```bash
sudo apt install python3-pip
```
Checking installations
```bash
pip3 --version
```
It must print something like
```bash
pip 9.0.1 from /usr/lib/python3/dist-packages (python 3.6)
```
This must show the python version installed
### requests Library
To install execute
```bash
pip install requests
```
To check installation use, on successfull installation it prints nothing
```bash
python3 -c "import requests"
```
### smtplib Library
To install execute
```bash
pip install smtplib
```
To check installation use, on successfull installation it prints nothing
```bash
python3 -c "import smtplib"
```
### ssl Library
To install execute
```bash
pip install ssl
```
To check installation use, on successfull installation it prints nothing
```bash
python3 -c "import ssl"
```
### sys Library
To install execute
```bash
pip install sys
```
To check installation use, on successfull installation it prints nothing
```bash
python3 -c "import sys"
```
### json Library
To install json
```bash
pip install json
```
To check installation use, on successfull installation it prints nothing
```bash
python3 -c "import json"
```
## Contributors of the Project
+ [Nivedit Jain](https://github.com/NiveditJain) (B18CSE039)
+ [Nagamalla Rohith](https://github.com/rohith-nagamalla) (B18CSE065)
+ [Muskan Bathla](https://github.com/MuskanBathla) (B18CSE036)
+ [Kumar Pradumn](https://github.com/kumar0912) (B18CSE024)
