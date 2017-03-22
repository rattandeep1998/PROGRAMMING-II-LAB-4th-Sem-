#include <bits/stdc++.h>
using namespace std;

class poly
{
	private :
		struct polynode
		{
			float coeff ;
			int exp ;
			polynode *link ;
		} *p ;
	public :
		poly()
		{
            p = NULL ;
        }

		void poly_append(float c,int e)
		{
            polynode *temp = p ;
            if ( temp == NULL )
            {
                temp = new polynode ;
                p = temp ;
            }
            else
            {
                while ( temp -> link != NULL )
                    temp = temp -> link ;
                temp -> link = new polynode ;
                temp = temp -> link ;
            }
            temp -> coeff = c ;
            temp -> exp = e ;
            temp -> link = NULL ;
        }

		void display_poly()
        {
            polynode *temp = p ;
            int f = 0 ;

            cout << endl ;
            while ( temp != NULL )
            {
                if ( f != 0 )
                {
                    if ( temp -> coeff > 0 )
                        cout << " + " ;
                    else
                        cout << " " ;
                }
                if ( temp -> exp != 0 )
                    cout << temp -> coeff << "x^" << temp -> exp ;
                else
                    cout << temp -> coeff ;
                temp = temp -> link ;
                f = 1 ;
            }
        }

		void poly_add( poly &l1, poly &l2)
        {
            polynode *z ;
            if ( l1.p == NULL && l2.p == NULL )
                return ;
            polynode *temp1, *temp2 ;
            temp1 = l1.p ;
            temp2 = l2.p ;
            while ( temp1 != NULL && temp2 != NULL )
            {
                if ( p == NULL )
                {
                    p = new polynode ;
                    z = p ;
                }
                else
                {
                    z -> link = new polynode ;
                    z = z -> link ;
                }
                if ( temp1 -> exp < temp2 -> exp )
                {
                    z -> coeff = temp2 -> coeff ;
                    z -> exp = temp2 -> exp ;
                    temp2 = temp2 -> link ;
                }
                else
                {
                    if ( temp1 -> exp > temp2 -> exp )
                    {
                        z -> coeff = temp1 -> coeff ;
                        z -> exp = temp1 -> exp ;
                        temp1 = temp1 -> link ;
                    }
                    else
                    {
                        if ( temp1 -> exp == temp2 -> exp )
                        {
                            z -> coeff = temp1 -> coeff + temp2 -> coeff ;
                            z -> exp = temp1 -> exp ;
                            temp1 = temp1 -> link ;
                            temp2 = temp2 -> link ;
                        }
                    }
                }
            }
            while ( temp1 != NULL )
            {
                if ( p == NULL )
                {
                    p = new polynode ;
                    z = p ;
                }
                else
                {
                    z -> link = new polynode ;
                    z = z -> link ;
                }
                z -> coeff = temp1 -> coeff ;
                z -> exp = temp1 -> exp ;
                temp1 = temp1 -> link ;
            }
            while ( temp2 != NULL )
            {
                if ( p == NULL )
                {
                    p = new polynode ;
                    z = p ;
                }
                else
                {
                    z -> link = new  polynode ;
                    z = z -> link ;
                }
                z -> coeff = temp2 -> coeff ;
                z -> exp = temp2 -> exp ;
                temp2 = temp2 -> link ;
            }
            z -> link = NULL ;
        }

		~poly()
		{
            polynode *q ;
            while ( p != NULL )
            {
                q = p -> link ;
                delete p ;
                p = q ;
            }
        }
} ;

int main( )
{
	poly p1 ;
	p1.poly_append ( 1.4, 5 ) ;
	p1.poly_append ( 1.5, 4 ) ;
	p1.poly_append ( 1.7, 2 ) ;
	p1.poly_append ( 1.8, 1 ) ;
	p1.poly_append ( 1.9, 0 ) ;
	cout << "\nFirst polynomial:" ;
	p1.display_poly( ) ;
	poly p2 ;
	p2.poly_append ( 1.5, 6 ) ;
	p2.poly_append ( 2.5, 5 ) ;
	p2.poly_append ( -3.5, 4 ) ;
	p2.poly_append ( 4.5, 3 ) ;
	p2.poly_append ( 6.5, 1 ) ;
	cout << "\nSecond polynomial:" ;
	p2.display_poly( ) ;
	poly p3 ;
	p3.poly_add ( p1, p2 ) ;
	cout << "\nResultant polynomial: " ;
	p3.display_poly( ) ;
    return 0;
}
