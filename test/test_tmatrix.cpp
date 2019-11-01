#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{	
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_NE(&m, &m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m.GetSize());
  
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][1] = 5;
	EXPECT_EQ(m[1][1], 5);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[7][7]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(3);
	m = m;
	EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{

	TMatrix<int> m(3),m1(3);
	m = m1;
	EXPECT_EQ(m1, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v(2), v1(3);
	ASSERT_NO_THROW(v = v1);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v(1), v1(2), v2(2);
	v[0][0] = 0;
	v1[0][0] = 1;
	v1[0][1] = 1;
	
	v1[1][1] = 1;
	v2[0][0] = 1;
	v2[0][1] = 1;
	
	v2[1][1] = 1;

  v = v1;

  EXPECT_EQ(v1, v2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	bool a = true;
	TMatrix<int> m(3), m1(3);
	m = m1;
	EXPECT_EQ((m1 == m), a);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	bool a = true;
	TMatrix<int> m(3);

	EXPECT_EQ((m == m), a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(3), m1(5);
	EXPECT_NE(m, m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(3), m1(3);
	ASSERT_NO_THROW(m + m1);
  
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(3), m1(3);
	ASSERT_NO_THROW(m - m1);

}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(3), m1(5);
	ASSERT_ANY_THROW(m - m1);
}

