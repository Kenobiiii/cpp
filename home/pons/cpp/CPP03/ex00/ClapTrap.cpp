ClapTrap::ClapTrap(const std::string& name) : name_(name) {
    Hit_points__ = 10;
    Energy_points_ = 10;
    Attack_damage_ = 0;
	std::cout << "ClapTrap constructor called for " << name_ << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (Hit_points__ <= 0) {
        std::cout << "ClapTrap " << name_ << " is dead and can't attack!" << std::endl;
        return;
    }
    if (Energy_points_ <= 0) {
        std::cout << "ClapTrap " << name_ << " has no energy to attack!" << std::endl;
        return;
    }

    Energy_points_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target 
              << ", causing " << Attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hit_points__ <= 0) {
        std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
        return;
    }

    Hit_points__ -= amount;
    if (Hit_points__ < 0) {
        Hit_points__ = 0;
    }

    std::cout << "ClapTrap " << name_ << " takes " << amount 
              << " points of damage! Hit points: " << Hit_points__ << std::endl;

    if (Hit_points__ == 0) {
        std::cout << "ClapTrap " << name_ << " has died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Hit_points__ <= 0) {
        std::cout << "ClapTrap " << name_ << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (Energy_points_ <= 0) {
        std::cout << "ClapTrap " << name_ << " has no energy to repair!" << std::endl;
        return;
    }

    Energy_points_--;
    Hit_points__ += amount;

    std::cout << "ClapTrap " << name_ << " repairs itself for " << amount 
              << " hit points! Current hit points: " << Hit_points__ << std::endl;
}
