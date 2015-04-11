<?php

/**
 * @file
 * Custom Ctools relationship custom plugin.
 *
 * We take a node context, lookup related content, return our custom flickr context.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Florida Drupal Camp Flickr Relationship'),
  'keyword' => 'florida_flickr_context',
  'description' => t('Adds a flickr context from existing nodecontext.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  // Callback function for our relationship plugin.
  'context' => 'florida_flickr_relationship_context',
  'settings form' => 'florida_flickr_relationship_settings',
);

/**
 * Return a new context based on an existing context.
 *
 * Node context comes in, custom context goes out.
 */
function florida_flickr_relationship_context($context, $conf) {
  if (empty($context->data)) {
    return ctools_context_create_empty('florida_flickr_context', NULL);
  }
  $node = $context->data;
  $data = new stdClass();

  $data->flickr_images = florida_get_flickr_images($node);
  $data->original_context = $node;

  // Custom context goes out.
  return ctools_context_create('florida_flickr_context', $data);
}

/**
 * Settings form for the relationship.
 */
function florida_flickr_relationship_settings($conf) {
  return array();
}

/**
 * Helper that probably badly uses the Flickr api to get 4 images that might be like our node's title.
 *
 * @param $node
 *
 * @return array
 */
function florida_get_flickr_images($node) {
  $title = filter_xss($node->title);
  $key = 'Key Goes Here';
  $url = 'https://api.flickr.com/services/rest/?method=flickr.photos.search&api_key=' . $key . '&format=json&nojsoncallback=1&text=' . $title;

  $result = drupal_http_request($url, array());

  if ($result->code == '200') {
    $image_data = drupal_json_decode($result->data);
    if (!empty($image_data['photos']['photo'])) {
      foreach ($image_data['photos']['photo'] as $photo) {
        $image_path = 'https://farm' . $photo['farm'] . '.staticflickr.com/' . $photo['server'] . '/' . $photo['id'] . '_' . $photo['secret'] . '_n.jpg';
        $variables = array(
          'path' => $image_path,
          'attributes' => array(),
        );
        $image[] = theme_image($variables);
        if (count($image) >= 4) {
          break;
        }
      }
    }
  }
  return $image;
}
