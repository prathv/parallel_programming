-- phpMyAdmin SQL Dump
-- version 2.11.9.4
-- http://www.phpmyadmin.net
--
-- Host: oniddb
-- Generation Time: Aug 07, 2016 at 10:12 PM
-- Server version: 5.5.49
-- PHP Version: 5.2.6-1+lenny16

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `raip-db`
--

-- --------------------------------------------------------

--
-- Table structure for table `Scores`
--

CREATE TABLE IF NOT EXISTS `Scores` (
  `username` varchar(10) NOT NULL,
  `game` varchar(10) NOT NULL,
  `score` int(10) DEFAULT '100',
  `wins` int(10) DEFAULT '0',
  `loses` int(10) DEFAULT '0',
  PRIMARY KEY (`username`,`game`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Scores`
--

INSERT INTO `Scores` (`username`, `game`, `score`, `wins`, `loses`) VALUES
('a', 'rps', 100, 0, 0),
('w', 'rps', 100, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE IF NOT EXISTS `Users` (
  `username` varchar(10) NOT NULL,
  `password` varchar(40) NOT NULL,
  `firstName` varchar(20) NOT NULL,
  `lastName` varchar(20) NOT NULL,
  `email` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`username`, `password`, `firstName`, `lastName`, `email`) VALUES
('w', 'w', 'w', 'w', 'w@gnail.com'),
('a', 'a', 'a', 'a', 'a@gmail.com');
