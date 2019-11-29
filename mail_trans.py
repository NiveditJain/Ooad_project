import smtplib
import ssl
import sys

try:
    port = 587  # For starttls
    smtp_server = "smtp.gmail.com"
    sender_email = "ccbasketiitjodhpur@gmail.com"
    receiver_email = sys.argv[1]+"@iitj.ac.in"
    password = "NiveditJain@ooad"
    message = """\
FROM: CC BASKET
TO: """+receiver_email+"""
Subject: Order Summary from CC Basket\n
Dear """+sys.argv[2]+"\n"+"Your order has been successfully placed "+",which costs "+sys.argv[3]+" Rupees. "+"It will be delivered to you by "+sys.argv[4]+"(Phone number "+sys.argv[5]+").\n"+"Your order payment mode is "+sys.argv[6]+".\n"+"For further details you can contact moderator by reaching Community Centre office or by replying to this thread."+"\n"+"Thank You for shopping with us."

    context = ssl.create_default_context()
    with smtplib.SMTP(smtp_server, port) as server:
        server.ehlo()  # Can be omitted
        server.starttls(context=context)
        server.ehlo()  # Can be omitted
        server.login(sender_email, password)
        server.sendmail(sender_email,receiver_email, message)
    with open(".junk","w") as file:
        file.write(str(1))
except:
    with open(".junk","w") as file:
        file.write(str(-1))