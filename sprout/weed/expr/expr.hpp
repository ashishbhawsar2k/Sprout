#ifndef SPROUT_WEED_EXPR_EXPR_HPP
#define SPROUT_WEED_EXPR_EXPR_HPP

#include <sprout/config.hpp>
#include <sprout/tuple/tuple.hpp>
#include <sprout/utility/forward.hpp>

namespace sprout {
	namespace weed {
		//
		// expr
		//
		template<typename Tag, typename... Args>
		class expr {
		public:
			typedef Tag expr_tag;
			typedef sprout::tuples::tuple<Args...> args_type;
		private:
			args_type args_;
		public:
			template<typename... As>
			SPROUT_CONSTEXPR explicit expr(As&&... args)
				: args_(sprout::forward<As>(args)...)
			{}
			SPROUT_CONSTEXPR args_type const& args() const {
				return args_;
			}
		};
	}	// namespace weed
}	// namespace sprout

#endif	// #ifndef SPROUT_WEED_EXPR_EXPR_HPP
