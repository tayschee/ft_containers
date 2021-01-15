R='\u001b[31m'
G='\u001b[32m'
B='\u001b[33m'
W='\u001b[0m'

STD_BIN='bin/test_std/'
FT_BIN='bin/test_ft/'

VEC='vector/'


echo -e "TEST VECTOR\n"

echo -e "DEFAULT CONSTRUCTOR and COPY CONSTRUCTOR AND CONSTRUCTOR(SIZE_TYPE) :"

diff <(${FT_BIN}${VEC}char_construct 1) <(${STD_BIN}${VEC}char_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <CHAR>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <CHAR>: KO${W}"
fi

diff <(${FT_BIN}${VEC}int_construct 1) <(${STD_BIN}${VEC}int_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <INT>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <INT>: KO${W}"
fi

diff <(${FT_BIN}${VEC}string_construct 1) <(${STD_BIN}${VEC}string_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <STRING>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <STRING>: KO${W}"
fi

diff <(${FT_BIN}${VEC}double_construct 1) <(${STD_BIN}${VEC}double_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <DOUBLE>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <DOUBLE>: KO${W}"
fi

diff <(${FT_BIN}${VEC}pointer_construct 1) <(${STD_BIN}${VEC}pointer_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <VOID *>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <VOID *>: KO${W}"
fi

diff <(${FT_BIN}${VEC}myclass_construct 1) <(${STD_BIN}${VEC}myclass_construct 1)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR <MY_CLASS>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR <MY_CLASS>: KO${W}"
fi

echo -e "${B}CONSTRUCTOR <BOOL>: KO${W}"



echo -e "\nITERATOR :"

diff <(${FT_BIN}${VEC}char_iterator) <(${STD_BIN}${VEC}char_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <CHAR>: OK${W}"
else
    echo -e "${R}ITERATOR <CHAR>: KO${W}"
fi

diff <(${FT_BIN}${VEC}int_iterator) <(${STD_BIN}${VEC}int_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <INT>: OK${W}"
else
    echo -e "${R}ITERATOR <INT>: KO${W}"
fi

diff <(${FT_BIN}${VEC}double_iterator) <(${STD_BIN}${VEC}double_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <DOUBLE>: OK${W}"
else
    echo -e "${R}ITERATOR <DOUBLE>: KO${W}"
fi

diff <(${FT_BIN}${VEC}string_iterator) <(${STD_BIN}${VEC}string_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <STRING>: OK${W}"
else
    echo -e "${R}ITERATOR <STRING>: KO${W}"
fi

diff <(${FT_BIN}${VEC}myclass_iterator) <(${STD_BIN}${VEC}myclass_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <MYCLASS>: OK${W}"
else
    echo -e "${R}ITERATOR <MYCLASS>: KO${W}"
fi



#diff <(${MBIN}my_construct_bool_vector 1) <(${BIN}construct_bool_vector 1)
#if [ ! $? -ne 0 ];
#then
#    echo -e "${G}CONSTRUCTOR <BOOLEAN> : OK${W}\n"
#else
#    echo -e "${R}CONSTRUCTOR <BOOLEAN> : KO${W}\n"
#fi

#diff <(${MBIN}my_iterator_test) <(${BIN}iterator_test)
#if [ ! $? -ne 0 ];
#then
#    echo -e "${G}VECTOR::ITERATOR : OK${W}\n"
#else
#    echo -e "${R}VECTOR::ITERATOR : KO${W}\n"
#fi