R='\u001b[31m'
G='\u001b[32m'
W='\u001b[0m'
BIN=binary/
MBIN=my_binary/

echo -e "TEST VECTOR"

#diff <(${MBIN}my_construct_vector 1) <(${BIN}construct_vector 1)
#if [ ! $? -ne 0 ];
#then
#    echo -e "${G}CONSTRUCTOR <CLASSIC TYPE>: OK${W}\n"
#else
#    echo -e "${R}CONSTRUCTOR <CLASSIC TYPE>: KO${W}\n"
#fi

#diff <(${MBIN}my_construct_bool_vector 1) <(${BIN}construct_bool_vector 1)
#if [ ! $? -ne 0 ];
#then
#    echo -e "${G}CONSTRUCTOR <BOOLEAN> : OK${W}\n"
#else
#    echo -e "${R}CONSTRUCTOR <BOOLEAN> : KO${W}\n"
#fi

diff <(${MBIN}my_iterator_test) <(${BIN}iterator_test)
if [ ! $? -ne 0 ];
then
    echo -e "${G}VECTOR::ITERATOR : OK${W}\n"
else
    echo -e "${R}VECTOR::ITERATOR : KO${W}\n"
fi