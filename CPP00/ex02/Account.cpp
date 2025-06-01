/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:58:08 by paromero          #+#    #+#             */
/*   Updated: 2025/05/31 21:11:11 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Static variable definitions - these must be initialized in the .cpp file
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Private static method to display timestamp in format [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);
    std::tm* timeinfo = std::localtime(&now);
    
    std::cout << "[" 
              << (timeinfo->tm_year + 1900)
              << (timeinfo->tm_mon + 1 < 10 ? "0" : "") << (timeinfo->tm_mon + 1)
              << (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday
              << "_"
              << (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour
              << (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min
              << (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec
              << "] ";
}

// Constructor - creates a new account with initial deposit
Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    // Assign index before incrementing total accounts
    _accountIndex = _nbAccounts;
    
    // Update static counters
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    // Display creation message: [timestamp] index:X;amount:Y;created
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

// Destructor - cleans up when account is destroyed
Account::~Account(void) {
    // Display destruction message: [timestamp] index:X;amount:Y;closed
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
}

// Returns current account balance
int Account::checkAmount(void) const {
    return _amount;
}

// Static getter functions - return global bank statistics
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// Static function to display global bank information
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Display individual account status
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Make a deposit to this account
void Account::makeDeposit(int deposit) {
    int p_amount = _amount;  // Store previous amount for logging
    
    // Update account values
    _amount += deposit;
    _nbDeposits++;
    
    // Update global bank statistics
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    // Display deposit message: [timestamp] index:X;p_amount:Y;deposit:Z;amount:W;nb_deposits:N
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Make a withdrawal from this account - returns true if successful, false if refused
bool Account::makeWithdrawal(int withdrawal) {
    int p_amount = _amount;  // Store previous amount for logging
    
    _displayTimestamp();
    
    // Check if withdrawal is possible
    if (withdrawal > _amount) {
        // Withdrawal refused - insufficient funds
        std::cout << "index:" << _accountIndex 
                  << ";p_amount:" << p_amount 
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    // Withdrawal successful - update values
    _amount -= withdrawal;
    _nbWithdrawals++;
    
    // Update global bank statistics
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    // Display successful withdrawal message
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return true;
}

