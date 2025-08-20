cmake_minimum_required(VERSION 3.29)
project(C___Primer)

set(CMAKE_CXX_STANDARD 20)

add_executable(C___Primer main.cpp
        include/Sales_item.h
        include/Sales_data.h
        include/Utils.h

        chapter_1/listing_io.cpp
        chapter_1/listing_comment.cpp
        chapter_1/listing_while.cpp
        chapter_1/listing_for.cpp
        chapter_1/listing_input_while.cpp
        chapter_1/listing_if.cpp
        chapter_1/listing_sales_item.cpp
        chapter_1/listing_sales_item_add.cpp
        chapter_1/listing_member_function.cpp
        chapter_1/listing_bookstore.cpp
        chapter_1/test_1_3.cpp
        chapter_1/test_1_4.cpp
        chapter_1/test_1_5.cpp
        chapter_1/test_1_6.cpp
        chapter_1/test_1_9.cpp
        chapter_1/test_1_10.cpp
        chapter_1/test_1_11.cpp
        chapter_1/test_1_12.cpp
        chapter_1/test_1_16.cpp
        chapter_1/test_1_20.cpp
        chapter_1/test_1_22.cpp
        chapter_1/test_1_23.cpp

        chapter_2/listing_literal.cpp
        chapter_2/listing_scope.cpp
        chapter_2/listing_reference.cpp
        chapter_2/listing_pointer.cpp
        chapter_2/listing_const.cpp
        chapter_2/listing_dealing_with_types.cpp
        chapter_2/listing_struct.cpp
        chapter_2/test_2_4.cpp
        chapter_2/test_2_8.cpp
        chapter_2/test_2_10.cpp
        chapter_2/test_2_13.cpp
        chapter_2/test_2_14.cpp
        chapter_2/test_2_17.cpp
        chapter_2/test_2_18.cpp
        chapter_2/test_2_20.cpp
        chapter_2/test_2_35.cpp
        chapter_2/test_2_36.cpp
        chapter_2/test_2_37.cpp
        chapter_2/test_2_38.cpp

        chapter_3/listing_using.cpp
        chapter_3/listing_string.cpp
        chapter_3/listing_vector.cpp
        chapter_3/test_3_2.cpp
        chapter_3/test_3_4.cpp
        chapter_3/test_3_5.cpp
        chapter_3/test_3_6.cpp
        chapter_3/test_3_7.cpp
        chapter_3/test_3_8.cpp
        chapter_3/test_3_9.cpp
        chapter_3/test_3_10.cpp
        chapter_3/test_3_11.cpp
        chapter_3/test_3_14.cpp
        chapter_3/test_3_15.cpp
        chapter_3/test_3_16.cpp
        chapter_3/test_3_17.cpp
        chapter_3/test_3_19.cpp
        chapter_3/test_3_20.cpp

)
