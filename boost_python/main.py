import hello, test

print(test.greet())
test.system("ls -l")

print('----w----')

w = hello.World('default value')
print(w.showmsg())
w.set('123')
print(w.showmsg())

print('----y----')

y = hello.World()
print(y.showmsg())
y.set('yyy')
print(y.showmsg())
print(y._msg)

y.msg = 'modified'
print(y.msg)

print('----x----')
x = hello.Var('pi')
x.value = 3.14
print(x.name, 'is around', x.value)

# print('----n----')
# n = hello.Num()
# n.value = 12.21
# print(n.value, n.rovalue)
print('----inherit----')
base = hello.Base()
class Derived(hello.Base):
	def f(self):
		return 42
	def g(self):
		return 1.234

derived = Derived()

def f(obj):
	print(id(obj), 'f', obj.f())
def g(obj):
	print(id(obj), 'g', obj.g())

f(derived)
f(base)

g(derived)

instance = hello.factory()
print(instance)
# print(instance.g())
c_derived = hello.Derived()
print(c_derived.f())
print(c_derived.g())

print(c_derived)