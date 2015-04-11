<?php

/**
 * @file
 * Ctools access plugin.
 */

$plugin = array(
  'title' => t('URL: Query string "dev"'),
  'description' => t('Controls access by a URL query string for developer access.'),
  'callback' => 'florida_dev_query_access_check',
  'settings form' => 'florida_dev_query_access_check_settings',
  'summary' => 'florida_dev_query_access_check_summary',
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function florida_dev_query_access_check($conf, $context) {
  global $user;
  // Authenticated users will only be able to see our panel.
  if ($user->uid > 0) {
    // Adding ?dev=1 to the query string will allow access to our panel.
    if (isset($_GET['dev']) && $_GET['dev'] === '1') {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Settings form for the 'dev_query' access plugin.
 */
function florida_dev_query_access_check_settings($form, &$form_state, $conf) {
  return $form;
}

/**
 * Provide a summary description for the 'dev_query' access plugin.
 */
function florida_dev_query_access_check_summary($conf, $context) {
  return t('Restrict access to only authenticated users who add ?dev=1 to the url.');
}
