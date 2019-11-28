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
Subject: OTP for CC Basket Account\n
Dear """+sys.argv[3]+"\n"+"Welcome to CC Basket IIT Jodhpur"+"\n""Your OTP is "+sys.argv[2]

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