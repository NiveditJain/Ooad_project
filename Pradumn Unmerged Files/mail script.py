import smtplib

server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
server.login("nivedit1jain@gmail.com","Nivedit@20")
server.sendmail(
  "nivedit1jain@iitj.ac.in", 
  "jain.22@iitj.ac.in",
  "this message is from f-bay Online Dilvery System, Thanks for Shopping with us")
server.quit()