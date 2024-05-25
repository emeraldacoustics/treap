#include <utility>
#include <vector>

using namespace std;

class TreapNode
{
public:
	int pri;
	TreapNode * son[2];

	pair<int, int> hsh;
	int sz;

	TreapNode(void);
	TreapNode(const pair<int, int> &);
};

inline int getsz(TreapNode * u)
{
	return u ? u->sz : 0;
}

inline void update(TreapNode * u)
{
	if (!u)
		return;

	u->sz = 1;
	for (int i = 0; i < 2; ++ i)
	{
		if (u->son[i])
			u += getsz(u->son[i]);
	}
}

inline TreapNode * merge(TreapNode * lu, TreapNode * ru)
{
	if (lu->pri >= ru->pri)
	{
		lu->son[1] = merge(lu->son[1], ru);
		update(lu);

		return lu;
	}
	else
	{
		ru->son[0] = merge(lu, ru->son[0]);
		update(ru);

		return ru;
	}
}

inline void split(TreapNode * u, int lsz, TreapNode * & lu, TreapNode * & ru)
{
	if (lsz <= 0)
	{
		lu = NULL;
		ru = u;
		return;
	}
	else if (lsz >= getsz(u))
	{
		lu = u;
		ru = NULL;
		return;
	}

	if (getsz(u->son[0]) <= lsz)
	{
		ru = u;
		split(u->son[0], lsz, lu, ru->son[0]);
	}
	else
	{
		lu = u;
		split(u->son[1], lsz - getsz(u->son[0]) - 1, lu->son[1], ru);
	}

	update(u);
	
	vector<int> a;
}

inline void remove(TreapNode * u)
{
	if (!u)
		return;

	for (int i = 0; i < 2; ++ i)
		remove(u->son[i]);

	delete u;
}

TreapNode::TreapNode(void) : pri(rand()), hsh(make_pair(0, 0)), sz(1)
{
	son[0] = son[1] = NULL;
}

TreapNode::TreapNode(const pair<int, int> & hsh) : pri(rand()), hsh(hsh), sz(1)
{
	son[0] = son[1] = NULL;
}
