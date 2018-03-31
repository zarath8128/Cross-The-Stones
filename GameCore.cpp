#include "GameCore.h"
#include <iostream>

namespace CrossTheStones{
	GameCore::GameCore(unsigned W, unsigned H):W(W), H(H), current_player(BLACK), buf(new State[W*H]){
		for(unsigned i = 0; i < W*H; ++i) buf[i] = EMPTY;
	}
	GameCore::~GameCore(){}

	State &GameCore::operator()(unsigned w, unsigned h){
		return buf[h*W + w];
	}
	const State &GameCore::operator()(unsigned w, unsigned h) const{
		return buf[h*W + w];
	}

	constexpr int sign(int n){return n > 0 ? 1 : n < 0 ? -1 : 0;}

	bool GameCore::move(unsigned wb, unsigned hb, unsigned we, unsigned he){
		std::cerr << wb << ", " << hb << ", " << we << ", " << he << "\n";
		if(!(wb < W && we < W && hb < H && he < H)) return false;
		std::cerr << __LINE__ << "\n";
		if((*this)(wb, hb) != current_player) return false;
		std::cerr << __LINE__ << "\n";
		if(!(wb == we || hb == he)) return false;
		std::cerr << __LINE__ << "\n";
		if(unsigned w = wb; w == we)
			for(unsigned h = he; h != hb; h += sign(hb - he))
				if((*this)(w, h) != EMPTY) return false;
		if(unsigned h = hb; h == he)
			for(unsigned w = we; w != wb; w += sign(wb - we))
				if((*this)(w, h) != EMPTY) return false;
		(*this)(we, he) = (*this)(wb, hb);
		(*this)(wb, hb) = EMPTY;

		return true;
	}

}
