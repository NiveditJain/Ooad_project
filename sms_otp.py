import requests
import sys
import json 

url = "https://www.fast2sms.com/dev/bulk"
 
payload = "sender_id=FSTSMS&message=Dear "+sys.argv[3]+",Welcome+to+CC+Basket+IIT+Jodhpur\nYour+OTP+is+"+sys.argv[2]+"&language=english&route=p&numbers="+sys.argv[1]
headers = {
 'authorization': "BVU3EenPbsfYhl194pN6zF5XjW0cIwKu7SLqxkmgtdZOyiHJrGWMJ6tcBex4CGzdsiIZny9Ff7SKQuEh",
 'Content-Type': "application/x-www-form-urlencoded",
 'Cache-Control': "no-cache",
 }
 
try:
    response = requests.request("POST", url, data=payload, headers=headers)
    response=response.json()
    if(response['return']==True):
        with open(".junk","w") as file:
            file.write(str(1))
    else:
        with open(".junk","w") as file:
            file.write(str(-1))
except:
    with open(".junk","w") as file:
        file.write(str(-1))