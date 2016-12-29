Dim a, b, c, apa
Dim userName


apa = 2

response.write(apa)

userName = "CoolUserxx123"
c = "!"

response.write("The userName is:" + userName + c + apa)
response.write(userName)

'should return NULL
response.write(a)

'should return NULL
response.write(b)

'should return "!"
response.write(c)

response.write("PROGRAM FINISHED")
