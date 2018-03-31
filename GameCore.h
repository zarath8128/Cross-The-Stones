#pragma once

namespace CrossTheStones{\
	enum State{
		EMPTY, 
		BLACK,
		WHITE,
	};
	
	struct GameCore{
		const unsigned W, H;
		State current_player;

		GameCore(unsigned W, unsigned H);
		~GameCore();
		State &operator()(unsigned w, unsigned h);
		const State &operator()(unsigned w, unsigned h) const;

		bool move(unsigned wb, unsigned hb, unsigned we, unsigned he);

	private:
		State *buf;
	};
}
