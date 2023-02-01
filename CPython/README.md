# 编译
## python编译
python setup.py build
python setup.py install
python setup.py sdist
## cmake编译
编译开启 -O3

# 调用方式
## 1 python原生调用
在生成物spam.so，文件夹下直接
#python
>>>import spam
>>>spam.system("ls -l")

install之后可以直接
#xxx.py
import spam
spam.system("ls -l")


## 2 c程序调用
PyRun_SimpleString("import spam");
PyRun_SimpleString("spam.system('ls -l')");
