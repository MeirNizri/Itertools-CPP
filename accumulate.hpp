/**
 * This class receives as any container or container-like input. 
 * it returns ew container-like that include partial sums. 
 * Another version can get another parameter which is a binary functure (with two arguments), 
 * and use it instead of a sum. 
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

using namespace std;
namespace itertools {
    
    class add{
    public:
        add() {}
        template <typename T> T operator()(T a, T b) const {
            return a + b;
        }
    };

    template <typename Container, typename BinFunctor=add> class accumulate {
        Container container;
        BinFunctor binFunctor;

    public:
        accumulate(const Container c, BinFunctor f=add()) : container(c), binFunctor(f) {}
      
        // Iterator of class accumulate
        class iterator {
            typename Container::iterator inner_itr;
            decltype(*(inner_itr)) sum;
            BinFunctor binFunctor;

        public:
            iterator(typename Container::iterator it, BinFunctor f) : inner_itr(it), sum(*it), binFunctor(f) {}

            auto operator*() const {
                return sum;
            }
            
            iterator& operator++() {
                inner_itr++;
                //sum = binFunctor(sum, *inner_itr);
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
			    inner_itr++;
                //sum = binFunctor(sum, *inner_itr);
			    return tmp;
    		}

            bool operator==(const iterator& it) const {
			    return inner_itr == it.inner_itr;
		    }

    		bool operator!=(const iterator& it) const {
			    return inner_itr != it.inner_itr;
    		}
    	};  // END OF CLASS ITERATOR


    	iterator begin() {
    		return iterator{container.begin(), binFunctor};
    	}

    	iterator end() {
    		return iterator{container.end(), binFunctor};
    	}
    }; 
}