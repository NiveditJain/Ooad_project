import requests
 
url = "https://www.fast2sms.com/dev/bulk"
 
payload = "sender_id=FSTSMS&message=Your+OTP+is+0000&language=english&route=p&numbers=8474985454"
headers = {
 'authorization': "BVU3EenPbsfYhl194pN6zF5XjW0cIwKu7SLqxkmgtdZOyiHJrGWMJ6tcBex4CGzdsiIZny9Ff7SKQuEh",
 'Content-Type': "application/x-www-form-urlencoded",
 'Cache-Control': "no-cache",
 }
 
response = requests.request("POST", url, data=payload, headers=headers)
 
print(response.text)