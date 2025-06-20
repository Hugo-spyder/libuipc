// Affine Body Revolute Joint Energy
template <typename T>
__host__ __device__ void Hess(Eigen::Matrix<T,12,12>& R, const T& kappa, const Eigen::Vector<T,3>& x0_bar, const Eigen::Vector<T,3>& x1_bar, const Eigen::Vector<T,3>& x2_bar, const Eigen::Vector<T,3>& x3_bar)
{
/*****************************************************************************************************************************
Function generated by SymEigen.py 
Author: MuGdxy
GitHub: https://github.com/MuGdxy/SymEigen
E-Mail: lxy819469559@gmail.com
******************************************************************************************************************************
LaTeX expression:
//tex:$$R = \left[\begin{array}{cccccccccccc}2 \kappa & 0 & 0 & \kappa \left(x_{1 bar(0)} + x_{3 bar(0)}\right) & \kappa \left(x_{1 bar(1)} + x_{3 bar(1)}\right) & \kappa \left(x_{1 bar(2)} + x_{3 bar(2)}\right) & 0 & 0 & 0 & 0 & 0 & 0\\0 & 2 \kappa & 0 & 0 & 0 & 0 & \kappa \left(x_{1 bar(0)} + x_{3 bar(0)}\right) & \kappa \left(x_{1 bar(1)} + x_{3 bar(1)}\right) & \kappa \left(x_{1 bar(2)} + x_{3 bar(2)}\right) & 0 & 0 & 0\\0 & 0 & 2 \kappa & 0 & 0 & 0 & 0 & 0 & 0 & \kappa \left(x_{1 bar(0)} + x_{3 bar(0)}\right) & \kappa \left(x_{1 bar(1)} + x_{3 bar(1)}\right) & \kappa \left(x_{1 bar(2)} + x_{3 bar(2)}\right)\\\kappa \left(x_{0 bar(0)} + x_{2 bar(0)}\right) & 0 & 0 & \kappa \left(x_{0 bar(0)} x_{1 bar(0)} + x_{2 bar(0)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(1)} + x_{2 bar(0)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(2)} + x_{2 bar(0)} x_{3 bar(2)}\right) & 0 & 0 & 0 & 0 & 0 & 0\\\kappa \left(x_{0 bar(1)} + x_{2 bar(1)}\right) & 0 & 0 & \kappa \left(x_{0 bar(1)} x_{1 bar(0)} + x_{2 bar(1)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(1)} + x_{2 bar(1)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(2)} + x_{2 bar(1)} x_{3 bar(2)}\right) & 0 & 0 & 0 & 0 & 0 & 0\\\kappa \left(x_{0 bar(2)} + x_{2 bar(2)}\right) & 0 & 0 & \kappa \left(x_{0 bar(2)} x_{1 bar(0)} + x_{2 bar(2)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(1)} + x_{2 bar(2)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(2)} + x_{2 bar(2)} x_{3 bar(2)}\right) & 0 & 0 & 0 & 0 & 0 & 0\\0 & \kappa \left(x_{0 bar(0)} + x_{2 bar(0)}\right) & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(0)} x_{1 bar(0)} + x_{2 bar(0)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(1)} + x_{2 bar(0)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(2)} + x_{2 bar(0)} x_{3 bar(2)}\right) & 0 & 0 & 0\\0 & \kappa \left(x_{0 bar(1)} + x_{2 bar(1)}\right) & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(1)} x_{1 bar(0)} + x_{2 bar(1)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(1)} + x_{2 bar(1)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(2)} + x_{2 bar(1)} x_{3 bar(2)}\right) & 0 & 0 & 0\\0 & \kappa \left(x_{0 bar(2)} + x_{2 bar(2)}\right) & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(2)} x_{1 bar(0)} + x_{2 bar(2)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(1)} + x_{2 bar(2)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(2)} + x_{2 bar(2)} x_{3 bar(2)}\right) & 0 & 0 & 0\\0 & 0 & \kappa \left(x_{0 bar(0)} + x_{2 bar(0)}\right) & 0 & 0 & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(0)} x_{1 bar(0)} + x_{2 bar(0)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(1)} + x_{2 bar(0)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(0)} x_{1 bar(2)} + x_{2 bar(0)} x_{3 bar(2)}\right)\\0 & 0 & \kappa \left(x_{0 bar(1)} + x_{2 bar(1)}\right) & 0 & 0 & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(1)} x_{1 bar(0)} + x_{2 bar(1)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(1)} + x_{2 bar(1)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(1)} x_{1 bar(2)} + x_{2 bar(1)} x_{3 bar(2)}\right)\\0 & 0 & \kappa \left(x_{0 bar(2)} + x_{2 bar(2)}\right) & 0 & 0 & 0 & 0 & 0 & 0 & \kappa \left(x_{0 bar(2)} x_{1 bar(0)} + x_{2 bar(2)} x_{3 bar(0)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(1)} + x_{2 bar(2)} x_{3 bar(1)}\right) & \kappa \left(x_{0 bar(2)} x_{1 bar(2)} + x_{2 bar(2)} x_{3 bar(2)}\right)\end{array}\right]$$

Symbol Name Mapping:
kappa:
    -> {}
    -> Matrix([[kappa]])
x0_bar:
    -> {}
    -> Matrix([[x0_bar(0)], [x0_bar(1)], [x0_bar(2)]])
x1_bar:
    -> {}
    -> Matrix([[x1_bar(0)], [x1_bar(1)], [x1_bar(2)]])
x2_bar:
    -> {}
    -> Matrix([[x2_bar(0)], [x2_bar(1)], [x2_bar(2)]])
x3_bar:
    -> {}
    -> Matrix([[x3_bar(0)], [x3_bar(1)], [x3_bar(2)]])
*****************************************************************************************************************************/
/* Sub Exprs */
auto x0 = 2*kappa;
auto x1 = kappa*(x1_bar(0) + x3_bar(0));
auto x2 = kappa*(x1_bar(1) + x3_bar(1));
auto x3 = kappa*(x1_bar(2) + x3_bar(2));
auto x4 = kappa*(x0_bar(0) + x2_bar(0));
auto x5 = kappa*(x0_bar(0)*x1_bar(0) + x2_bar(0)*x3_bar(0));
auto x6 = kappa*(x0_bar(0)*x1_bar(1) + x2_bar(0)*x3_bar(1));
auto x7 = kappa*(x0_bar(0)*x1_bar(2) + x2_bar(0)*x3_bar(2));
auto x8 = kappa*(x0_bar(1) + x2_bar(1));
auto x9 = kappa*(x0_bar(1)*x1_bar(0) + x2_bar(1)*x3_bar(0));
auto x10 = kappa*(x0_bar(1)*x1_bar(1) + x2_bar(1)*x3_bar(1));
auto x11 = kappa*(x0_bar(1)*x1_bar(2) + x2_bar(1)*x3_bar(2));
auto x12 = kappa*(x0_bar(2) + x2_bar(2));
auto x13 = kappa*(x0_bar(2)*x1_bar(0) + x2_bar(2)*x3_bar(0));
auto x14 = kappa*(x0_bar(2)*x1_bar(1) + x2_bar(2)*x3_bar(1));
auto x15 = kappa*(x0_bar(2)*x1_bar(2) + x2_bar(2)*x3_bar(2));
/* Simplified Expr */
R(0,0) = x0;
R(0,1) = 0;
R(0,2) = 0;
R(0,3) = x1;
R(0,4) = x2;
R(0,5) = x3;
R(0,6) = 0;
R(0,7) = 0;
R(0,8) = 0;
R(0,9) = 0;
R(0,10) = 0;
R(0,11) = 0;
R(1,0) = 0;
R(1,1) = x0;
R(1,2) = 0;
R(1,3) = 0;
R(1,4) = 0;
R(1,5) = 0;
R(1,6) = x1;
R(1,7) = x2;
R(1,8) = x3;
R(1,9) = 0;
R(1,10) = 0;
R(1,11) = 0;
R(2,0) = 0;
R(2,1) = 0;
R(2,2) = x0;
R(2,3) = 0;
R(2,4) = 0;
R(2,5) = 0;
R(2,6) = 0;
R(2,7) = 0;
R(2,8) = 0;
R(2,9) = x1;
R(2,10) = x2;
R(2,11) = x3;
R(3,0) = x4;
R(3,1) = 0;
R(3,2) = 0;
R(3,3) = x5;
R(3,4) = x6;
R(3,5) = x7;
R(3,6) = 0;
R(3,7) = 0;
R(3,8) = 0;
R(3,9) = 0;
R(3,10) = 0;
R(3,11) = 0;
R(4,0) = x8;
R(4,1) = 0;
R(4,2) = 0;
R(4,3) = x9;
R(4,4) = x10;
R(4,5) = x11;
R(4,6) = 0;
R(4,7) = 0;
R(4,8) = 0;
R(4,9) = 0;
R(4,10) = 0;
R(4,11) = 0;
R(5,0) = x12;
R(5,1) = 0;
R(5,2) = 0;
R(5,3) = x13;
R(5,4) = x14;
R(5,5) = x15;
R(5,6) = 0;
R(5,7) = 0;
R(5,8) = 0;
R(5,9) = 0;
R(5,10) = 0;
R(5,11) = 0;
R(6,0) = 0;
R(6,1) = x4;
R(6,2) = 0;
R(6,3) = 0;
R(6,4) = 0;
R(6,5) = 0;
R(6,6) = x5;
R(6,7) = x6;
R(6,8) = x7;
R(6,9) = 0;
R(6,10) = 0;
R(6,11) = 0;
R(7,0) = 0;
R(7,1) = x8;
R(7,2) = 0;
R(7,3) = 0;
R(7,4) = 0;
R(7,5) = 0;
R(7,6) = x9;
R(7,7) = x10;
R(7,8) = x11;
R(7,9) = 0;
R(7,10) = 0;
R(7,11) = 0;
R(8,0) = 0;
R(8,1) = x12;
R(8,2) = 0;
R(8,3) = 0;
R(8,4) = 0;
R(8,5) = 0;
R(8,6) = x13;
R(8,7) = x14;
R(8,8) = x15;
R(8,9) = 0;
R(8,10) = 0;
R(8,11) = 0;
R(9,0) = 0;
R(9,1) = 0;
R(9,2) = x4;
R(9,3) = 0;
R(9,4) = 0;
R(9,5) = 0;
R(9,6) = 0;
R(9,7) = 0;
R(9,8) = 0;
R(9,9) = x5;
R(9,10) = x6;
R(9,11) = x7;
R(10,0) = 0;
R(10,1) = 0;
R(10,2) = x8;
R(10,3) = 0;
R(10,4) = 0;
R(10,5) = 0;
R(10,6) = 0;
R(10,7) = 0;
R(10,8) = 0;
R(10,9) = x9;
R(10,10) = x10;
R(10,11) = x11;
R(11,0) = 0;
R(11,1) = 0;
R(11,2) = x12;
R(11,3) = 0;
R(11,4) = 0;
R(11,5) = 0;
R(11,6) = 0;
R(11,7) = 0;
R(11,8) = 0;
R(11,9) = x13;
R(11,10) = x14;
R(11,11) = x15;
}
