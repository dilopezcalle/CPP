#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	// ===== Contructor =====
	Fixed();
	Fixed(const Fixed &src);

	// ===== Destructor =====
	~Fixed();

	// ===== Getters =====
	int		getRawBits(void) const;

	// ===== Setters =====
	void	setRawBits(int const raw);

	// ===== Methods =====
	Fixed	&operator=(const Fixed &src);


private:
	int					_rawBits;
	const static int	fracBits = 8;
};

#endif