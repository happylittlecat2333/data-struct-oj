	
f=file
#obj=$(patsubst %.cpp, %, f)
myprog:
#	g++ ${f} -o ${obj}  &&  ./${obj}
	g++ -std=c++11 -stdlib=libc++ ${f} -o a && ./a
