<%
Dim x, y, z, arr, elem

x = "Hello World"
y = "John Doe"
arr = Array(x, y, z)

response.write(x)

For Each elem In arr
    response.write(elem) 
Next


If i < 10 Then
    response.write(x)
Else
    response.write(y)
End If

%>
