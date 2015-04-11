<?php

/**
 * @file
 * Custom context custom plugin.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Florida Drupal Camp Flickr Context'),
  'description' => t('Context that deals with Flickr related images.'),
  // Function to create the relcontext.
  'context' => 'florida_flickr_context_create',
  'settings form' => 'florida_flickr_context_settings',
  'keyword' => 'florida_flickr_context',
  'context name' => 'florida_flickr_context',
);

/**
 * Create the context.
 */
function florida_flickr_context_create($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('florida_flickr_context');
  $context->plugin = 'florida_flickr_context';
  if ($empty) {
    return $context;
  }
  if (!empty($data)) {
    $context->data = $data;
    $context->title = t('Florida Drupal Camp Context');
    $context->keyword = 'florida_flickr_context';
    return $context;
  }
}

/**
 * Settings form.
 */
function florida_flickr_context_settings($conf, $external = FALSE) {
  $form = array();
  return $form;
}