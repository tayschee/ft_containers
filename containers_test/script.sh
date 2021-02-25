R='\u001b[31m'
G='\u001b[32m'
B='\u001b[33m'
W='\u001b[0m'

STD_BIN='bin/test_std/'
FT_BIN='bin/test_ft/'


VEC='vector/'
LIST='list/'


echo -e "TEST VECTOR\n"

<<C
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


echo -e "\nITERATOR :"

diff <(${FT_BIN}${VEC}char_iterator) <(${STD_BIN}${VEC}char_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <CHAR>: OK${W}"
else
    echo -e "${R}ITERATOR <CHAR>: KO${W}"
fi

diff <(${FT_BIN}${VEC}struct_iterator) <(${STD_BIN}${VEC}struct_iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR <STRUCT>: OK${W}"
else
    echo -e "${R}ITERATOR <STRUCT>: KO${W}"
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

echo -e "\nCONSTRUCTOR WITH ITERATOR :"

diff <(${FT_BIN}${VEC}char_construct2) <(${STD_BIN}${VEC}char_construct2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR(2) <CHAR>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR(2) <CHAR>: KO${W}"
fi

diff <(${FT_BIN}${VEC}int_construct2) <(${STD_BIN}${VEC}int_construct2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR(2) <INT>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR(2) <INT>: KO${W}"
fi

diff <(${FT_BIN}${VEC}float_construct2) <(${STD_BIN}${VEC}float_construct2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR(2) <FLOAT>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR(2) <FLOAT>: KO${W}"
fi

diff <(${FT_BIN}${VEC}struct_construct2) <(${STD_BIN}${VEC}struct_construct2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR(2) <STRUCT>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR(2) <STRUCT>: KO${W}"
fi

diff <(${FT_BIN}${VEC}string_construct2) <(${STD_BIN}${VEC}string_construct2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR(2) <STRING>: OK${W}"
else
    echo -e "${R}CONSTRUCTOR(2) <STRING>: KO${W}"
fi

echo -e "\nCAPACITY FUNCTION:"

diff <(${FT_BIN}${VEC}reserve) <(${STD_BIN}${VEC}reserve)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESERVE : OK${W}"
else
    echo -e "${R}RESERVE : KO${W}"
fi

diff <(${FT_BIN}${VEC}resize) <(${STD_BIN}${VEC}resize)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESIZE : OK${W}"
else
    echo -e "${R}RESIZE : KO${W}"
fi

echo -e "\nELEMENT ACCESS FUNCTION\n"

diff <(${FT_BIN}${VEC}at) <(${STD_BIN}${VEC}at)
if [ ! $? -ne 0 ];
then
    echo -e "${G}AT : OK${W}"
else
    echo -e "${R}AT : KO${W}"
fi


echo -e "\nMODIFIERS FUNCTION\n"

diff <(${FT_BIN}${VEC}assign) <(${STD_BIN}${VEC}assign)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ASSIGN : OK${W}"
else
    echo -e "${R}ASSIGN : KO${W}"
fi

diff <(${FT_BIN}${VEC}push_pop) <(${STD_BIN}${VEC}push_pop)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH_POP : OK${W}"
else
    echo -e "${R}PUSH_POP : KO${W}"
fi

diff <(${FT_BIN}${VEC}erase) <(${STD_BIN}${VEC}erase)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ERASE : OK${W}"
else
    echo -e "${R}ERASE : KO${W}"
fi


diff <(${FT_BIN}${VEC}swap_clear) <(${STD_BIN}${VEC}swap_clear)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SWAP AND CLEAR : OK${W}"
else
    echo -e "${R}SWAP AND CLEAR : KO${W}"
fi



diff <(${FT_BIN}${VEC}insert) <(${STD_BIN}${VEC}insert)
if [ ! $? -ne 0 ];
then
    echo -e "${G}INSERT : OK${W}"
else
    echo -e "${R}INSERT : KO${W}"
fi

C

echo -e "TEST LIST\n"

<<C
C
diff <(${FT_BIN}${LIST}default_constructor) <(${STD_BIN}${LIST}default_constructor)
if [ ! $? -ne 0 ];
then
    echo -e "${G}DEFAULT CONSTRUCTOR : OK${W}"
else
    echo -e "${R}DEFAULT CONSTRUCTOR : KO${W}"
fi

diff <(${FT_BIN}${LIST}constructor2) <(${STD_BIN}${LIST}constructor2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR 2 : OK${W}"
else
    echo -e "${R}CONSTRUCTOR 2 : KO${W}"
fi


diff <(${FT_BIN}${LIST}push_pop_front) <(${STD_BIN}${LIST}push_pop_front)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH POP FRONT : OK${W}"
else
    echo -e "${R}PUSH POP FRONT : KO${W}"
fi


diff <(${FT_BIN}${LIST}push_pop_back) <(${STD_BIN}${LIST}push_pop_back)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH POP BACK : OK${W}"
else
    echo -e "${R}PUSH POP BACK : KO${W}"
fi


diff <(${FT_BIN}${LIST}iterator) <(${STD_BIN}${LIST}iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR : OK${W}"
else
    echo -e "${R}ITERATOR : KO${W}"
fi


diff <(${FT_BIN}${LIST}constructor3) <(${STD_BIN}${LIST}constructor3)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR 3 : OK${W}"
else
    echo -e "${R}CONSTRUCTOR 3 : KO${W}"
fi

diff <(${FT_BIN}${LIST}assign) <(${STD_BIN}${LIST}assign)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ASSIGN : OK${W}"
else
    echo -e "${R}ASSIGN : KO${W}"
fi

diff <(${FT_BIN}${LIST}resize) <(${STD_BIN}${LIST}resize)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESIZE : OK${W}"
else
    echo -e "${R}RESIZE : KO${W}"
fi


diff <(${FT_BIN}${LIST}clear) <(${STD_BIN}${LIST}clear)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CLEAR : OK${W}"
else
    echo -e "${R}CLEAR : KO${W}"
fi


diff <(${FT_BIN}${LIST}swap) <(${STD_BIN}${LIST}swap)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SWAP : OK${W}"
else
    echo -e "${R}SWAP : KO${W}"
fi


diff <(${FT_BIN}${LIST}erase) <(${STD_BIN}${LIST}erase)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ERASE : OK${W}"
else
    echo -e "${R}ERASE : KO${W}"
fi


diff <(${FT_BIN}${LIST}insert) <(${STD_BIN}${LIST}insert)
if [ ! $? -ne 0 ];
then
    echo -e "${G}INSERT : OK${W}"
else
    echo -e "${R}INSERT : KO${W}"
fi


diff <(${FT_BIN}${LIST}splice) <(${STD_BIN}${LIST}splice)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SPLICE : OK${W}"
else
    echo -e "${R}SPLICE : KO${W}"
fi



diff <(${FT_BIN}${LIST}remove) <(${STD_BIN}${LIST}remove)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REMOVE : OK${W}"
else
    echo -e "${R}REMOVE : KO${W}"
fi


diff <(${FT_BIN}${LIST}remove_if) <(${STD_BIN}${LIST}remove_if)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REMOVE_IF : OK${W}"
else
    echo -e "${R}REMOVE_IF : KO${W}"
fi

diff <(${FT_BIN}${LIST}unique) <(${STD_BIN}${LIST}unique)
if [ ! $? -ne 0 ];
then
    echo -e "${G}UNIQUE : OK${W}"
else
    echo -e "${R}UNIQUE : KO${W}"
fi

diff <(${FT_BIN}${LIST}merge) <(${STD_BIN}${LIST}merge)
if [ ! $? -ne 0 ];
then
    echo -e "${G}MERGE : OK${W}"
else
    echo -e "${R}MERGE : KO${W}"
fi


diff <(${FT_BIN}${LIST}sort) <(${STD_BIN}${LIST}sort)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SORT : OK${W}"
else
    echo -e "${R}SORT : KO${W}"
fi

diff <(${FT_BIN}${LIST}sort) <(${STD_BIN}${LIST}sort)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SORT : OK${W}"
else
    echo -e "${R}SORT : KO${W}"
fi


diff <(${FT_BIN}${LIST}reverse) <(${STD_BIN}${LIST}reverse)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REVERSE : OK${W}"
else
    echo -e "${R}REVERSE : KO${W}"
fi



diff <(${FT_BIN}${LIST}operator) <(${STD_BIN}${LIST}operator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}OPERATOR : OK${W}"
else
    echo -e "${R}OPERATOR : KO${W}"
fi