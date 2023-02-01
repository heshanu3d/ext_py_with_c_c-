import hello, test

print(test.greet())
test.system("ls -l")

w = hello.World()
print(w.showmsg())
w.set('123')
print(w.showmsg())
