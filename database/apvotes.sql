DROP TABLE IF EXISTS `apvotes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `apvotes` (
    `id` int NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `vote_id` int NOT NULL DEFAULT '0',
    `vote_var_id` int NOT NULL DEFAULT '0',
    `account_id` int NOT NULL DEFAULT '0',
    `date` int NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;