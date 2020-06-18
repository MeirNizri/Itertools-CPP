/**
 * This class receives as input two parameters: the first is a boolean functor representing a condition, 
 * and the second is a container or container-like. 
 * Returns a new container-like, which includes only the elements in the given container-like, 
 * that fulfill the condition.
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

using namespace std;
namespace itertools {

    template <typename BinFunctor, typename Container> class filterfalse {
        Container container;
        BinFunctor binFunctor;
        
    public:
        filterfalse(BinFunctor f, const Container c) : binFunctor(f), container(c) {}
    
        // Iterator of class filterfalse
        class iterator{
            typename Container::iterator inner_itr;
            BinFunctor binFunctor;
            
        public:
            iterator(typename Container::iterator it, BinFunctor f) : inner_itr(it), binFunctor(f) {}

            auto operator*() const {
                return *inner_itr;
            }
            
            iterator& operator++() {
                inner_itr++;
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
			    inner_itr++;
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